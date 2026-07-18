#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"
CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
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
    //测试
    ListItemBox* listItemBox = new ListItemBox(this);
     QListWidgetItem* listWidgetItem = new QListWidgetItem(ui->pageMusicList);
     listWidgetItem->setSizeHint(QSize(ui->pageMusicList->width(), 45));
     ui->pageMusicList->setItemWidget(listWidgetItem, listItemBox);


}

void CommonPage::setMusicListType(PageType pageType)
{
    this->pageType=pageType;
}

void CommonPage::reFresh(MusicList &musicList)
{
    addMusicToMusicPage(musicList);
    for(auto musicId:musicListOfPage)
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

        QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->pageMusicList);
        listWidgetItem->setSizeHint(QSize(ui->pageMusicList->width(),45));
        ui->pageMusicList->setItemWidget(listWidgetItem, listItemBox);


    }
    repaint();
}

void CommonPage::addMusicToMusicPage(MusicList &musicList)
{
    //清空旧内容
    musicListOfPage.clear();
    for(auto& music : musicList)
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
