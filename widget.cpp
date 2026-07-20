#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include "volumetool.h"
#include <QDir>
 #include <QFileDialog>
#include<QStandardPaths>
#include<QUrl>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QImage>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initUI();
    initPlayer();
    connectSignalAdnSlot();



}

Widget::~Widget()
{
    delete ui;
}

 VolumeTool* volumeTool;
void Widget::initUI()
{
   setWindowFlag(Qt::WindowType::FramelessWindowHint);


    //设置背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *shadowEffect =new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(10);//设置模糊半径
    shadowEffect->setOffset(0,0);//设置阴影偏移
    shadowEffect->setColor(QColor(0,0,0));//阴影颜色
   this->setGraphicsEffect(shadowEffect);


   //设置BodyLeft中的btFrom
   ui->rec->setIcon(":/images/rec.png", "推荐", 0);
    ui->radio->setIcon(":/images/radio.png", "电台", 1);
    ui->music->setIcon(":/images/music.png", "⾳乐馆", 2);

    ui->like->setIcon(":/images/like.png", "我喜欢", 3);
    ui->local->setIcon(":/images/local.png", "本地下载", 4);
    ui->recent->setIcon(":/images/recent.png", "最近播放", 5);

    //设置默认选中本地下载
    ui->local->animalShow();
    ui->stackedWidget->setCurrentIndex(4);
    curpage = ui->localPage;

    srand(time(NULL));
    ui->recMusicBox->initRecBoxUi(randomPiction(),1);
    ui->supplyMusicBox->initRecBoxUi(randomPiction(),2);

    volumeTool = new VolumeTool(this);
    //设置commonpage的信息
    ui->likePage->setMusicListType(PageType::LIKE_PAGE);
    ui->likePage->setCommonPageUI("我喜欢", ":/images/ilikebg.png");
    ui->localPage->setMusicListType(PageType::LOCAL_PAGE);
    ui->localPage->setCommonPageUI("本地音乐",":/images/localbg.png");
    ui->recentPage->setMusicListType(PageType::HISTORY_PAGE);
    ui->recentPage->setCommonPageUI("最近播放",":/images/recentbg.png");

    // 底部封面使用固定尺寸，防止大尺寸内嵌图片把控制区布局撑开。
    ui->gridLayout->setContentsMargins(5,5,5,5);
    ui->musicCover->setFixedSize(50,50);
    ui->musicCover->setAlignment(Qt::AlignCenter);
    setCurrentMusicCover(QPixmap(":/images/default_cover.png"));

    // 播放控制区按钮图标设定
    ui->play->setIcon(QIcon(":/images/play_2.png"));
    ui->playMode->setIcon(QIcon(":/images/shuffle_2.png"));
    volumeTool = new VolumeTool(this);


}
QJsonArray Widget::randomPiction()
    {
QVector<QString> vecImageName;
 vecImageName<<"001.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"<<"007.png"
     <<"008.png"<<"009.png"<<"010.png"<<"011.png"<<"012.png"<<"013.png"
     <<"014.png"<<"015.png"<<"016.png"<<"017.png"<<"018.png" <<"019.png"
     <<"020.png"<<"021.png"<<"022.png"<<"023.png"<<"024.png" <<"025.png"
     <<"026.png"<<"027.png"<<"028.png"<<"029.png"<<"030.png" <<"031.png"
     <<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"<<"037.png"
     <<"038.png"<<"039.png"<<"040.png";

     std::random_shuffle(vecImageName.begin(), vecImageName.end());


     QJsonArray objArray;
    for(int i = 0; i < vecImageName.size(); ++i)
     {
     QJsonObject obj;
     obj.insert("path", ":/images/rec/"+vecImageName[i]);


         QString strText = QString("推荐-%1").arg(i, 3, 10, QChar('0'));
     obj.insert("text", strText);

         objArray.append(obj);

         }

    return objArray;
     }

void Widget::setCurrentMusicCover(const QPixmap &pixmap)
{
    ui->musicCover->setScaledContents(false);
    ui->musicCover->setPixmap(
        pixmap.scaled(ui->musicCover->size(),
                      Qt::KeepAspectRatio,
                      Qt::SmoothTransformation));
}




void Widget::mousePressEvent(QMouseEvent *event)
{

    //event->globalPos() 获取鼠标全局屏幕坐标
    //frameGeometry().topLeft()取出这个窗口外框矩形的左上角屏幕全局坐标
    //
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();

        // qDebug()<<dragPosition;
        return ;
    }

    QWidget::mousePressEvent(event);


}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);//窗口左上角新全局坐标

        return;

    }
    QWidget::mouseMoveEvent(event);

}

void Widget::connectSignalAdnSlot()//关联信号槽
{
    connect(ui->rec,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->music,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->radio,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->like,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->local,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->recent,&BtForm::click,this,&Widget::onBtFormClick);

    connect(ui->likePage,&CommonPage::updateLikeMusic,this,&Widget::onUpdateLikeMusic);

    connect(ui->localPage,&CommonPage::updateLikeMusic,this,&Widget::onUpdateLikeMusic);

    connect(ui->recentPage,&CommonPage::updateLikeMusic,this,&Widget::onUpdateLikeMusic);



    // 播放控制区的信号和槽函数关联
    connect(ui->play, &QPushButton::clicked, this, &Widget::onPlayCliked);
    connect(ui->playUp, &QPushButton::clicked, this, &Widget::onPlayUpCliked);
    connect(ui->playDown, &QPushButton::clicked, this, &Widget::onPlayDownCliked);
    // 播放列表的模式放改变时的信号槽关联
    connect(playList, &QMediaPlaylist::playbackModeChanged, this, &Widget::onPlaybackModeChanged);

    //关联播放所有的信号和槽函数
    connect(ui->likePage,&CommonPage::playAll,this,&Widget::onPlayAll);
     connect(ui->localPage,&CommonPage::playAll,this,&Widget::onPlayAll);
     connect(ui->recentPage,&CommonPage::playAll,this,&Widget::onPlayAll);

     //处理likePage、localPage、recentPage中ListItemBox双击
     connect(ui->likePage,&CommonPage::playMusicByIndex,this,&Widget::playMusicByIndex);
      connect(ui->localPage,&CommonPage::playMusicByIndex,this,&Widget::playMusicByIndex);
      connect(ui->recentPage,&CommonPage::playMusicByIndex,this,&Widget::playMusicByIndex);

      // 设置静音槽函数
      connect(volumeTool,&VolumeTool::setSilence,this,&Widget::setMusicSilence);

      //设置音量大小
      connect(volumeTool,&VolumeTool::setMusicVolume,this,&Widget::setPlayerVolume);
}

void Widget::initPlayer()
{
    //创建播放器
    player=new QMediaPlayer(this);
    //创建播放列表
    playList=new QMediaPlaylist(this);
    //设置播放模式
    playList->setPlaybackMode(QMediaPlaylist::Loop);
    //将播放列表设置给播放器
    player->setPlaylist(playList);

    //设置音量
    player->setVolume(20);
    // QMediaPlayer信号和槽函数关联
    // 播放状态改变时：暂停和播放之间切换
    connect(player, &QMediaPlayer::stateChanged, this,&Widget::onPlayStateChanged);

    // 播放列表切换歌曲时，更新当前歌曲ID和播放历史。
    connect(playList,&QMediaPlaylist::currentIndexChanged,
            this,&Widget::onCurrentIndexChanged);

    // 新歌曲的元数据解析完成后，更新歌曲名称、歌手和封面。
    connect(player,&QMediaPlayer::metaDataAvailableChanged,
            this,&Widget::onMetaDataAvailableChanged);

    // 播放器位置变化时，自动更新底部播放进度条。
    connect(player,&QMediaPlayer::positionChanged,this,[this](qint64 position)
            {
        ui->processBar->setProgress(position,player->duration());
    });

    // 切换歌曲或媒体加载完成时，使用新的总时长刷新进度条。
    connect(player,&QMediaPlayer::durationChanged,this,[this](qint64 duration)
            {
        ui->processBar->setProgress(player->position(),duration);
    });

    // 用户拖动完成后，将播放器跳转到对应位置。
    connect(ui->processBar,&MusicSlide::seekRequested,this,[this](double ratio)
            {
        if(player->duration()>0)
        {
            player->setPosition(qRound64(player->duration()*ratio));
        }
    });

    connect(ui->playMode, &QPushButton::clicked, this, &Widget::onPlaybackModeCliked);
}

void Widget::onBtFormClick(int pageid)
{
    //1找到所有BtForm所有按钮对象
    QList<BtForm*>buttonList=this->findChildren<BtForm*>();
    //2.查找对象，如果不是当前Id的对象清楚显示背景颜色
    foreach (BtForm* btitem, buttonList)
         {
        if (pageid != btitem->getId())
             {
                 btitem->clearBg();
             }
        }
    //3显示当前显示的页面
        ui->stackedWidget->setCurrentIndex(pageid);
        qDebug()<<pageid;
}
void Widget::on_quit_clicked()
{
    this->close();
}


void Widget::on_volume_clicked()
{
    QPoint point = ui->volume->mapToGlobal(QPoint(0,0));


         QPoint volumeLeftTop = point - QPoint(volumeTool->width()/2, volumeTool->height());


         volumeLeftTop.setY(volumeLeftTop.y()+30);
     volumeLeftTop.setX(volumeLeftTop.x()+15);


         volumeTool->move(volumeLeftTop);


         volumeTool->show();
}


void Widget::on_addLocal_clicked()
{
    //创建文件对话框
    QFileDialog fileDialog(this);
    fileDialog.setWindowTitle("添加本地音乐");
    //创建打开格式的文件文件
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    //设置对话框
    //设置只能选择文件，可以选择多个文件
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    //设置音乐过滤器
    fileDialog.setNameFilters({
        tr("音乐文件 (*.mp3 *.wav *.flac *.m4a *.aac *.ogg)"),
        tr("所有文件 (*.*)")
    });

    //设置对话框的打开路径
    QDir dir(QDir::currentPath());
    dir.cdUp();
    QString musicPath =
        "C:/Users/18074/Desktop/qtcode/QtQQMusic/musics";
    fileDialog.setDirectory(musicPath);

    //显示模态对话框，用户取消时直接返回
    if(fileDialog.exec()!=QFileDialog::Accepted)
    {
        return;
    }

    //一次性获取并提交用户选择的全部文件，避免在循环中重复添加整批歌曲
    const QList<QUrl> urls=fileDialog.selectedUrls();
    if(urls.isEmpty())
    {
        return;
    }

    musicList.addMusicByUrl(urls);
    ui->localPage->reFresh(musicList);

    // 根据最新的本地音乐数据重新生成播放列表。
    // 先清空可以避免多次导入时重复加入已经存在的歌曲。
    playList->clear();
    ui->localPage->addMusicToPlayer(musicList, playList);
    if (!playList->isEmpty())
    {
        playList->setCurrentIndex(0);
    }

    ui->stackedWidget->setCurrentIndex(4);
}



void Widget::onPlayCliked()
{
    qDebug()<<"播放按钮点击";
    if(player->state()==QMediaPlayer::PlayingState)
    {
        // 如果是歌曲正在播放中，按下播放键，此时应该暂停播放
        player->pause();
    }
    else if(player->state()==QMediaPlayer::PausedState)
    {
        // 如果是暂停状态，按下播放键，继续开始播放
        player->play();
    }
    else if(player->state()==QMediaPlayer::StoppedState)
    {
        player->play();
    }
}

void Widget::onPlayStateChanged()
{
    qDebug()<<"播放状态改变";

    if(player->state() == QMediaPlayer::PlayingState){
        //开始状态
        ui->play->setIcon(QIcon(":/images/play_on.png"));
    }
    else{
        //暂停状态
        ui->play->setIcon(QIcon(":/images/play3.png"));
    }
}

void Widget::onPlayUpCliked()
{
    if(playList->mediaCount()==0)
    {
        return;
    }

    // 单曲循环会让previous()仍然停留在当前歌曲，
    // 因此手动计算上一首歌曲的索引。
    if(playList->playbackMode()==QMediaPlaylist::CurrentItemInLoop)
    {
        const int currentIndex=playList->currentIndex();
        const int previousIndex=currentIndex<=0
                                    ? playList->mediaCount()-1
                                    : currentIndex-1;
        playList->setCurrentIndex(previousIndex);
        return;
    }

    playList->previous();
}

void Widget::onPlayDownCliked()
{
    if(playList->mediaCount()==0)
    {
        return;
    }

    // 单曲循环状态下仍允许用户手动选择下一首歌曲。
    if(playList->playbackMode()==QMediaPlaylist::CurrentItemInLoop)
    {
        const int currentIndex=playList->currentIndex();
        const int nextIndex=currentIndex<0
                                ? 0
                                : (currentIndex+1)%playList->mediaCount();
        playList->setCurrentIndex(nextIndex);
        return;
    }

    playList->next();
}

void Widget::onPlaybackModeCliked()
{
    if(playList->playbackMode() == QMediaPlaylist::Loop)
    {
        // 列表循环
        ui->playMode->setToolTip("随机播放");
        playList->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(playList->playbackMode() == QMediaPlaylist::Random)
    {
        // 随机播放
        ui->playMode->setToolTip("单曲循环");
        playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    }
    else if(playList->playbackMode() == QMediaPlaylist::CurrentItemInLoop){
        ui->playMode->setToolTip("列表循环");
        playList->setPlaybackMode(QMediaPlaylist::Loop);
    }
    else{
        qDebug()<<"播放模式错误";
    }
}

void Widget::onPlaybackModeChanged(QMediaPlaylist::PlaybackMode playbackMode)
{
    if(playbackMode == QMediaPlaylist::Loop)
    {
        ui->playMode->setIcon(QIcon(":/images/list_play.png"));
    }
    else if(playbackMode == QMediaPlaylist::Random)
    {
        ui->playMode->setIcon(QIcon(":/images/shuffle_2.png"));
    }
    else if(playbackMode == QMediaPlaylist::CurrentItemInLoop)
    {
        ui->playMode->setIcon(QIcon(":/images/single_play.png"));
    }
    else{
        qDebug()<<"暂不⽀持该模式";
    }
}

void Widget::onPlayAll(PageType pageType)
{
    CommonPage *page=nullptr;
    switch (pageType) {
    case PageType::LIKE_PAGE:
    {        page=ui->likePage;
        break;
    }
    case PageType::LOCAL_PAGE:{
        page=ui->localPage;
        break;
    }
    case PageType::HISTORY_PAGE:
    {
        page=ui->recentPage;
        break;
    }
    default:
        qDebug()<<"等待扩展";
    }
    playAllOfCommonpage(page,0);
}

void Widget::playAllOfCommonpage(CommonPage *commonpage, int index)
{
    curpage=commonpage;
    // 播放page所在所有的音乐
    //将播放列表清空
    playList->clear();
    // 将当前页面歌曲添加到播放列表
    commonpage->addMusicToPlayer(musicList,playList);
    // 设置当前播放列表的索引
    playList->setCurrentIndex(index);

    player->play();
}

void Widget::playMusicByIndex(CommonPage *page, int index)
{
    playAllOfCommonpage(page,index);
}

void Widget::onCurrentIndexChanged(int index)
{
    if(index<0 || curpage==nullptr)
    {
        return;
    }

    // 音乐乐的id都在commonPage中的musicListOfPage中存储着
    const QString musicId =curpage->getMusicIdByIndex(index);

    if(musicId.isEmpty())
    {
        return;
    }

    auto it=musicList.findMusicById(musicId);

    if(it !=musicList.end())
    {
        currentMusicId=musicId;

        // 将该音乐设置为历史播放记录
        it->setIsHistory(true);

        // 元数据是异步解析的，先使用Music对象中已有的信息。
        ui->musicName->setText(it->getMusicName());
        ui->musicSinger->setText(it->getSingerName());

        // 切歌时先显示默认封面，解析到内嵌封面后再替换。
        const QPixmap defaultCover(":/images/default_cover.png");
        setCurrentMusicCover(defaultCover);
        curpage->setImageLabel(defaultCover);
    }
    ui->recentPage->reFresh(musicList);

}

void Widget::onMetaDataAvailableChanged(bool available)
{
    if(!available)
    {
        return;
    }

    qDebug()<<"歌曲切换，元数据读取完成";

    QString musicName=player->metaData(QMediaMetaData::Title).toString();

    const QVariant authorData=player->metaData(QMediaMetaData::Author);
    QString singer=authorData.toStringList().join(",");
    if(singer.isEmpty())
    {
        singer=authorData.toString();
    }

    // 元数据缺少名称或歌手时，使用Music对象中保存的备用信息。
    auto it=musicList.findMusicById(currentMusicId);
    if(it!=musicList.end())
    {
        if(musicName.isEmpty())
        {
            musicName=it->getMusicName();
        }
        if(singer.isEmpty())
        {
            singer=it->getSingerName();
        }
    }

    ui->musicName->setText(musicName);
    ui->musicSinger->setText(singer);

    QPixmap coverPixmap;
    const QVariant coverData=player->metaData(QMediaMetaData::ThumbnailImage);
    if(coverData.isValid())
    {
        const QImage coverImage=coverData.value<QImage>();
        if(!coverImage.isNull())
        {
            coverPixmap=QPixmap::fromImage(coverImage);
        }
    }

    // 歌曲没有内嵌封面时使用默认封面。
    if(coverPixmap.isNull())
    {
        coverPixmap.load(":/images/default_cover.png");
    }

    setCurrentMusicCover(coverPixmap);

    if(curpage!=nullptr)
    {
        curpage->setImageLabel(coverPixmap);
    }
}

void Widget::setMusicSilence(bool isMuted)
{
    player->setMuted(isMuted);
}

void Widget::setPlayerVolume(int vomume)
{
    player->setVolume(vomume);
}

void Widget::onDurationChanged(qint64 duration)
{

}

void Widget::onUpdateLikeMusic(bool isLike, QString musicId)
{
    auto it=musicList.findMusicById(musicId);

    if( it!=musicList.end())
    {
        it->setIsLike(isLike);
    }
    ui->likePage->reFresh(musicList);
     ui->localPage->reFresh(musicList);
     ui->recentPage->reFresh(musicList);
}
