#ifndef COMMONPAGE_H
#define COMMONPAGE_H
#include "musiclist.h"
#include <QWidget>
#include <QMediaPlaylist>
#include <QPixmap>
#include <algorithm>
namespace Ui {
class CommonPage;
}
enum PageType{
    LIKE_PAGE,// 我喜欢
    LOCAL_PAGE,//本地下载
    HISTORY_PAGE// 最近播放

};



class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    ~CommonPage();
    void setCommonPageUI(const QString &text, const QString &imagePath);
    void setMusicListType(PageType pageType);
    void reFresh(MusicList& musicList);
    //将歌曲加入播放的媒体列表
    void addMusicToPlayer(MusicList &musicList, QMediaPlaylist *playList);

    //根据歌曲在列表中的索引获取歌曲 ID”
    QString getMusicIdByIndex(int index) const;

    // 设置当前页面顶部显示的歌曲封面。
    void setImageLabel(const QPixmap &pixmap);

private:
    void addMusicToMusicPage(MusicList &musicList);

signals:
    void updateLikeMusic(bool isLike,QString musicId);
    void playAll(PageType pageType);

    void playMusicByIndex(CommonPage*, int);

private:
    Ui::CommonPage *ui;
    QVector<QString> musicListOfPage;
    PageType pageType;
};


#endif // COMMONPAGE_H
