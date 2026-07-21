#ifndef LRCPAGE_H
#define LRCPAGE_H

#include <QWidget>
#include <QVector>

namespace Ui {
class LrcPage;
}

struct LyricLine
{
    qint64 time;//时间
    QString text;//歌词

    LyricLine(qint64 qtime,QString qtext)
        :time(qtime)
        ,text(qtext)
    {}
};

class LrcPage : public QWidget
{
    Q_OBJECT

public:
    explicit LrcPage(QWidget *parent = nullptr);
    ~LrcPage();
    bool parseLrc(const QString &lrcPath);
    void setMusicInfo(const QString &musicName, const QString &singerName);
    void updateLyric(qint64 position);

private:
    void clearLyrics(const QString &message);

private:
    Ui::LrcPage *ui;
    QVector<LyricLine> lrcLines;
    int currentLineIndex;
};

#endif // LRCPAGE_H
