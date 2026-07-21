#include "lrcpage.h"
#include "ui_lrcpage.h"
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QRegularExpression>
#include <QTextStream>
#include <algorithm>

LrcPage::LrcPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LrcPage)
    , currentLineIndex(-1)
{
    ui->setupUi(this);

    connect(ui->hideBtn,&QPushButton::clicked,this,[this](){
        hide();
    });
    ui->hideBtn->setIcon(QIcon(":/images/xiala.png"));
    clearLyrics(QStringLiteral("暂无歌词"));
}

LrcPage::~LrcPage()
{
    delete ui;
}

bool LrcPage::parseLrc(const QString &lrcPath)
{
    lrcLines.clear();
    currentLineIndex=-1;

    QFile lrcFile(lrcPath);
    if(!lrcFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"无法打开歌词文件:"<<lrcPath;
        clearLyrics(QStringLiteral("暂无歌词"));
        return false;
    }

    QTextStream stream(&lrcFile);
    stream.setCodec("UTF-8");

    // 支持[00:12.34]、[00:12:340]、项目中的[0:9.970.00]
    // 以及一行多个时间标签。
    const QRegularExpression timeExpression(
        QStringLiteral("\\[(\\d{1,3}):(\\d{1,2})(?:[\\.:](\\d{1,3}))?(?:\\.\\d+)?\\]"));

    while(!stream.atEnd())
    {
        const QString line=stream.readLine();
        QRegularExpressionMatchIterator matches=timeExpression.globalMatch(line);
        QVector<QRegularExpressionMatch> timeMatches;
        int lyricStart=0;

        while(matches.hasNext())
        {
            const QRegularExpressionMatch match=matches.next();
            timeMatches.push_back(match);
            lyricStart=match.capturedEnd();
        }

        if(timeMatches.isEmpty())
        {
            continue;
        }

        const QString lyricText=line.mid(lyricStart).trimmed();
        for(const QRegularExpressionMatch &match : timeMatches)
        {
            const int minutes=match.captured(1).toInt();
            const int seconds=match.captured(2).toInt();
            QString fraction=match.captured(3);

            int milliseconds=0;
            if(!fraction.isEmpty())
            {
                if(fraction.size()==1)
                {
                    milliseconds=fraction.toInt()*100;
                }
                else if(fraction.size()==2)
                {
                    milliseconds=fraction.toInt()*10;
                }
                else
                {
                    milliseconds=fraction.left(3).toInt();
                }
            }

            const qint64 lineTime=minutes*60*1000
                                   +seconds*1000
                                   +milliseconds;
            lrcLines.push_back(LyricLine(lineTime,lyricText));
        }
    }

    std::stable_sort(lrcLines.begin(),lrcLines.end(),
                     [](const LyricLine &left,const LyricLine &right)
                     {
        return left.time<right.time;
    });

    if(lrcLines.isEmpty())
    {
        clearLyrics(QStringLiteral("暂无歌词"));
        return false;
    }

    updateLyric(0);
    return true;
}

void LrcPage::setMusicInfo(const QString &musicName, const QString &singerName)
{
    ui->musicName->setText(musicName);
    ui->musicSinge->setText(singerName);
}

void LrcPage::updateLyric(qint64 position)
{
    if(lrcLines.isEmpty())
    {
        return;
    }

    // 二分查找当前播放时间对应的最后一行歌词。
    int left=0;
    int right=lrcLines.size()-1;
    int lineIndex=-1;
    while(left<=right)
    {
        const int middle=left+(right-left)/2;
        if(lrcLines.at(middle).time<=position)
        {
            lineIndex=middle;
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }

    // 第一行歌词出现前，先把第一行放在中央等待。
    if(lineIndex<0)
    {
        lineIndex=0;
    }

    if(lineIndex==currentLineIndex)
    {
        return;
    }
    currentLineIndex=lineIndex;

    QLabel *labels[]={ui->line1,ui->line2,ui->line3,ui->lineCenter,
                      ui->line4,ui->line5,ui->line6};
    for(int row=0;row<7;++row)
    {
        const int lyricIndex=currentLineIndex+row-3;
        labels[row]->setText(lyricIndex>=0 && lyricIndex<lrcLines.size()
                                 ? lrcLines.at(lyricIndex).text
                                 : QString());
    }
}

void LrcPage::clearLyrics(const QString &message)
{
    currentLineIndex=-1;
    ui->line1->clear();
    ui->line2->clear();
    ui->line3->clear();
    ui->lineCenter->setText(message);
    ui->line4->clear();
    ui->line5->clear();
    ui->line6->clear();
}
