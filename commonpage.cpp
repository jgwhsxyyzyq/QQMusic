#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"
#include <algorithm>
CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
    ui->pageMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(ui->playAllBtn,&QPushButton::clicked,this,[=](){
        emit(playAll(pageType));
    });
    // 鼠标标双击后，发射信号告诉Widget，博能放this页面中共被双击的歌曲
    connect(ui->pageMusicList,&QListWidget::doubleClicked,this,[=](const QModelIndex & index){
        emit playMusicByIndex(this,index.row());
    });
}

CommonPage::~CommonPage()
{
    delete ui;

}

void CommonPage::setCommonPageUI(const QString &text, const QString &imagePath)
{
    //设置文本
    ui->pageTittle->setText(text);
    //设置推荐页面，并保持图片原始宽高比。
    setImageLabel(QPixmap(imagePath));
}

void CommonPage::setMusicListType(PageType pageType)
{
    this->pageType=pageType;
}

void CommonPage::reFresh(MusicList &musicList)
{
    //刷新前清除旧列表项，避免重复显示
    ui->pageMusicList->clear();

    addMusicToMusicPage(musicList);
    const auto &pageMusicIds=musicListOfPage;
    for(const QString &musicId : pageMusicIds)
    {
        auto it=musicList.findMusicById(musicId);
        if(it==musicList.end())
        {
            continue;
        }



        ListItemBox *listItemBox=new ListItemBox(ui->pageMusicList);
        listItemBox->setMusicName(it->getMusicName());
        listItemBox->setAlbumName(it->getAlbumName());
        listItemBox->setSinger(it->getSingerName());
        listItemBox->setLikeIcon(it->getIsLike());

        //一首歌曲只创建一个列表项，否则同一个ListItemBox会被移动到
        //第二个列表项中，留下一个空白行。
        QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->pageMusicList);
        listWidgetItem->setSizeHint(QSize(0,45));
        listWidgetItem->setData(Qt::UserRole,musicId);
        ui->pageMusicList->setItemWidget(listWidgetItem,listItemBox);

         // 接收ListItemBox发射的setLikeMusic信号
         connect(listItemBox,&ListItemBox::setIsLike,this,[this,musicId](bool isLike)
                 {
        emit updateLikeMusic(isLike,musicId);

         });


    }

   ui->pageMusicList->viewport()->update();
}

void CommonPage::addMusicToPlayer(MusicList &musicList, QMediaPlaylist *playList)
{
    // 播放列表必须与页面显示的歌曲ID顺序一致。
    // 特别是最近播放页面经过时间排序后，不能再按原始MusicList顺序添加媒体。
    addMusicToMusicPage(musicList);

    for(const QString &musicId : musicListOfPage)
    {
        auto it=musicList.findMusicById(musicId);
        if(it==musicList.end())
        {
            continue;
        }

        playList->addMedia(it->getMusicUrl());
    }
}

QString CommonPage::getMusicIdByIndex(int index) const
{
    if(index<0 || index>=musicListOfPage.size())
    {
        qDebug()<<"没有该歌曲";
        return QString();
    }
    return  musicListOfPage.at(index);
}

void CommonPage::setImageLabel(const QPixmap &pixmap)
{
    ui->musicImageLabel->setScaledContents(false);
    ui->musicImageLabel->setAlignment(Qt::AlignCenter);
    ui->musicImageLabel->setPixmap(
        pixmap.scaled(ui->musicImageLabel->size(),
                      Qt::KeepAspectRatio,
                      Qt::SmoothTransformation));
}

void CommonPage::addMusicToMusicPage(MusicList &musicList)
{
    //清空旧内容
    musicListOfPage.clear();

    // 最近播放页面单独按照最后播放时间排序，避免改变本地音乐和收藏页面的顺序。
    if(pageType==HISTORY_PAGE)
    {
        QVector<const Music *> historyMusic;
        for(const Music &music : musicList)
        {
            if(music.getIsHistory())
            {
                historyMusic.push_back(&music);
            }
        }

        std::sort(historyMusic.begin(),
                  historyMusic.end(),
                  [](const Music *left, const Music *right)
        {
            return left->getLastPlayTime()>right->getLastPlayTime();
        });

        for(const Music *music : historyMusic)
        {
            musicListOfPage.push_back(music->getMusicId());
        }
        return;
    }

    for(auto &music : musicList)
    {
        switch (pageType) {
        case LOCAL_PAGE:
        {
            musicListOfPage.push_back(music.getMusicId());
            break;
        }
        case LIKE_PAGE:
            {
                if(music.getIsLike())
                     {
                         musicListOfPage.push_back(music.getMusicId());
                   }
                 break;
            }

        case HISTORY_PAGE:
            break;
        default:
            break;
        }
    }
}
