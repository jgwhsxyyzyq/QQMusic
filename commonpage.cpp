#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"
CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
    ui->pageMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

CommonPage::~CommonPage()
{
    delete ui;

}

void CommonPage::setCommonPageUI(const QString &text, const QString &imagePath)
{
    //设置文本
    ui->pageTittle->setText(text);
    //设置推荐页面
    ui->musicImageLabel->setPixmap(imagePath);
    //设置缩放
    ui->musicImageLabel->setScaledContents(true);
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
    for(auto music:musicList)
    {
        switch (pageType) {
        case LOCAL_PAGE:
        {
            playList->addMedia(music.getMusicUrl());
            break;
        }
        case LIKE_PAGE:
        {
            if(music.getIsLike())
            {
                playList->addMedia(music.getMusicUrl());
            }
            break;
        }
        case HISTORY_PAGE:
        {
            if(music.getIsHistory())
            {
                playList->addMedia(music.getMusicUrl());
            }
            break;
        }

        default:
            break;
        }
    }
}

void CommonPage::addMusicToMusicPage(MusicList &musicList)
{
    //清空旧内容
    musicListOfPage.clear();
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
            {
                if(music.getIsHistory())
            {
                musicListOfPage.push_back(music.getMusicId());
                }

            }
        default:
            break;
        }
    }
}
