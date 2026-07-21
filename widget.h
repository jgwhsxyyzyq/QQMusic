#ifndef WIDGET_H
#define WIDGET_H
#include "musiclist.h"
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsDropShadowEffect>
#include<QJsonObject>
#include <QMediaPlaylist>
#include <QJsonArray>
#include <QMediaPlayer>
#include "commonpage.h"
#include "lrcpage.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
    void initUI();
    QJsonArray randomPiction();
    void initPlayer();
    void onPlayCliked();
    void onPlayStateChanged();
    void onPlayUpCliked();
    void onPlayDownCliked();
    // 播放模式设置
    void onPlaybackModeCliked();
    // 播放模式切换槽函数
    void onPlaybackModeChanged(QMediaPlaylist::PlaybackMode playbackMode);

    //播放所有的槽函数
    void onPlayAll(PageType pageType);
    void playAllOfCommonpage(CommonPage *commonpage ,int index);
    // CommonPage中playMusicByIndex信号对应槽函数
    void playMusicByIndex(CommonPage* page, int index);
    // 支持播放历史记录
    void onCurrentIndexChanged(int index);

    // 当前歌曲的媒体元数据解析完成后更新歌曲信息和封面。
    void onMetaDataAvailableChanged(bool available);

    //设置静音状态
    void setMusicSilence(bool isMuted);

    void setPlayerVolume(int vomume); // 设置音量大小

    // 歌曲持续时长改变时[歌曲切换]
    void onDurationChanged(qint64 duration);

    // 播放位置改变，即持续播放时间改变
    void onPositionChanged(qint64 duration);

// 歌词按钮槽函数
    void onLrcWordClicked();


protected:
    void mousePressEvent(QMouseEvent*event)override;
    void mouseMoveEvent(QMouseEvent*event)override;
    void resizeEvent(QResizeEvent *event) override;
    void connectSignalAdnSlot();




private slots:
    void on_quit_clicked();
    void onBtFormClick(int pageid);
    void onUpdateLikeMusic(bool isLike, QString musicId);

    void on_volume_clicked();

    void on_addLocal_clicked();




private:
    void setCurrentMusicCover(const QPixmap &pixmap);

    Ui::Widget *ui;
    QPoint dragPosition;
    MusicList musicList;
    //播放器相关
    QMediaPlayer* player;
    // 要多首歌曲播放，以及更复杂的播放设置，需要给播放器设置媒体列表
    QMediaPlaylist* playList;
    QString currentMusicId;

    CommonPage*curpage;

    //歌词页面相关
    LrcPage* lrcPage=nullptr;


};
#endif // WIDGET_H
