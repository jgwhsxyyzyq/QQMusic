#ifndef MUSIC_H
#define MUSIC_H

#include <QUrl>
#include <QString>
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QUuid>
class Music
{
public:
    // 创建一个空的音乐对象。
    Music();

    // 根据音乐文件的 URL 创建音乐对象。
    Music(const QUrl& url);

    // 设置歌曲是否被收藏：true 表示已收藏，false 表示未收藏。
    void setIsLike(bool isLike);

    // 设置歌曲是否进入播放历史：true 表示播放过，false 表示未播放。
    void setIsHistory(bool isHistory);

    // 设置歌曲名称。
    void setMusicName(const QString& musicName);

    // 设置歌手名称。
    void setSingerName(const QString& singerName);

    // 设置专辑名称。
    void setAlbumName(const QString& albumName);

    // 设置歌曲总时长，单位通常为毫秒。
    void setDuration(const qint64 duration);

    // 设置歌曲文件的 URL，例如 file:///C:/musics/test.mp3。
    void setMusicUrl(const QUrl& url);

    // 设置歌曲的唯一标识，可以使用歌曲 ID 或规范化后的文件路径。
    void setMusicId(const QString& musicId);

    // 获取歌曲是否已被收藏。
    bool getIsLike();

    // 获取歌曲是否进入播放历史。
    bool getIsHistory();

    // 获取歌曲名称。
    QString getMusicName();

    // 获取歌手名称。
    QString getSingerName();

    // 获取专辑名称。
    QString getAlbumName();

    // 获取歌曲总时长，单位通常为毫秒。
    qint64 getDuration();

    // 获取歌曲文件的 URL。
    QUrl getMusicUrl();

    // 获取歌曲的唯一标识。
    QString getMusicId();

    QString getLrcFilePath() const;



private:
    // 收藏状态。
    bool isLike;

    // 播放历史状态。
    bool isHistory;

    // 歌曲名称。
    QString musicName;

    // 歌手名称。
    QString singerName;

    // 专辑名称。
    QString albumName;

    // 歌曲总时长，单位为毫秒。
    qint64 duration;

    // 歌曲唯一标识。
    QString musicId;

    // 歌曲文件地址。
    QUrl musicUrl;
private:
    void parseMediaMetaData();

};

#endif // MUSIC_H
