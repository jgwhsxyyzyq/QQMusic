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
protected:
    void mousePressEvent(QMouseEvent*event)override;
     void mouseMoveEvent(QMouseEvent*event)override;
    void connectSignalAdnSlot();




private slots:
    void on_quit_clicked();
    void onBtFormClick(int pageid);
    void onUpdateLikeMusic(bool isLike, QString musicId);

    void on_volume_clicked();

    void on_addLocal_clicked();




private:
    Ui::Widget *ui;
    QPoint dragPosition;
    MusicList musicList;
    //播放器相关
    QMediaPlayer* player;
    // 要多首歌曲播放，以及更复杂的播放设置，需要给播放器设置媒体列表
    QMediaPlaylist* playList;
    QString currentMusicId;



};
#endif // WIDGET_H
