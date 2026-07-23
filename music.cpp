#include "music.h"
#include <QFileInfo>
#include <QDir>
#include <QEventLoop>
#include <QMediaMetaData>
#include <QObject>
#include <QTimer>

Music::Music()
    : isLike(false)
    , isHistory(false)
    , duration(0)
    , lastPlayTime(0)

{
}

Music::Music(const QUrl &url)
: isLike(false)
, isHistory(false)
, duration(0)
,musicUrl(url)
,lastPlayTime(0)




{

    musicId=QUuid::createUuid().toString();
    parseMediaMetaData();
}

void Music::setIsLike(bool isLike)
{
    this->isLike=isLike;
}

void Music::setIsHistory(bool isHistory)
{
    this->isHistory=isHistory;
}

void Music::setMusicName(const QString &musicName)
{
    this->musicName=musicName;
}

void Music::setSingerName(const QString &singerName)
{
    this->singerName=singerName;
}

void Music::setAlbumName(const QString &albumName)
{
    this->albumName=albumName;
}

void Music::setDuration(const qint64 duration)
{
    this->duration=duration;
}

void Music::setMusicUrl(const QUrl &url)
{
    this->musicUrl=url;
}

void Music::setMusicId(const QString &musicId)
{
    this->musicId=musicId;
}

bool Music::getIsLike() const
{
    return isLike;
}

bool Music::getIsHistory() const
{
    return isHistory;
}

QString Music::getMusicName() const
{
    return musicName;
}

QString Music::getSingerName() const
{
    return singerName;
}

QString Music::getAlbumName() const
{
    return albumName;
}

qint64 Music::getDuration() const
{
    return duration;
}

QUrl Music::getMusicUrl() const
{
    return musicUrl;
}

QString Music::getMusicId() const
{
    return musicId;
}

QString Music::getLrcFilePath() const
{
    const QFileInfo musicFile(musicUrl.toLocalFile());
    return QDir(musicFile.absolutePath())
        .filePath(musicFile.completeBaseName()+QStringLiteral(".lrc"));
}

void Music::setLastPlayTime(qint64 lastPlayTime)
{
    this->lastPlayTime=lastPlayTime;
}

qint64 Music::getLastPlayTime() const
{
    return lastPlayTime;
}

void Music::parseMediaMetaData()
{
    QMediaPlayer player;
    QEventLoop waitLoop;
    QTimer timeoutTimer;
    bool timedOut=false;

    timeoutTimer.setSingleShot(true);

    // 元数据可用、媒体加载结束或媒体无效时，都结束等待。
    // 不能再使用没有退出条件的while循环，否则异常文件会卡住整个导入过程。
    QObject::connect(&player,&QMediaPlayer::metaDataAvailableChanged,
                     &waitLoop,[&waitLoop](bool available)
            {
        if(available)
        {
            waitLoop.quit();
        }
    });

    QObject::connect(&player,&QMediaPlayer::mediaStatusChanged,
                     &waitLoop,[&waitLoop](QMediaPlayer::MediaStatus status)
            {
        if(status==QMediaPlayer::LoadedMedia
            || status==QMediaPlayer::BufferedMedia
            || status==QMediaPlayer::InvalidMedia
            || status==QMediaPlayer::NoMedia)
        {
            // 让同一轮事件队列中的元数据信号先处理完。
            QTimer::singleShot(0,&waitLoop,&QEventLoop::quit);
        }
    });

    QObject::connect(&timeoutTimer,&QTimer::timeout,
                     &waitLoop,[&waitLoop,&timedOut]()
            {
        timedOut=true;
        waitLoop.quit();
    });

    // 本地文件最多等待3秒。超时后使用文件名作为备用歌曲信息。
    player.setMedia(QMediaContent(musicUrl));
    if(!player.isMetaDataAvailable()
        && player.mediaStatus()!=QMediaPlayer::LoadedMedia
        && player.mediaStatus()!=QMediaPlayer::BufferedMedia
        && player.mediaStatus()!=QMediaPlayer::InvalidMedia
        && player.mediaStatus()!=QMediaPlayer::NoMedia)
    {
        timeoutTimer.start(3000);
        waitLoop.exec(QEventLoop::ExcludeUserInputEvents);
    }

    if(timeoutTimer.isActive())
    {
        timeoutTimer.stop();
    }

    if(player.isMetaDataAvailable())
    {
        musicName=player.metaData(QMediaMetaData::Title).toString();

        const QVariant authorData=player.metaData(QMediaMetaData::Author);
        singerName=authorData.toStringList().join(",");
        if(singerName.isEmpty())
        {
            singerName=authorData.toString();
        }

        albumName=player.metaData(QMediaMetaData::AlbumTitle).toString();
    }

    // 没有标题、歌手等标签的歌曲通常仍然可以得到播放时长。
    duration=player.duration();
    if(duration<=0)
    {
        duration=player.metaData(QMediaMetaData::Duration).toLongLong();
    }

    if(timedOut)
    {
        qWarning()<<"读取音乐元数据超时，将使用文件名作为备用信息:"
                  <<musicUrl.toLocalFile();
    }
    else if(player.mediaStatus()==QMediaPlayer::InvalidMedia)
    {
        qWarning()<<"音乐文件无效:"<<musicUrl.toLocalFile()
                  <<player.errorString();
    }

    // 无论元数据是否可用，都为缺失字段设置备用内容。
    const QFileInfo fileInfo(musicUrl.toLocalFile());
    const QString fileName=fileInfo.completeBaseName();
    const QString separator=" - ";
    const int index=fileName.indexOf(separator);

    if(musicName.isEmpty())
    {
        musicName=index!=-1
                        ? fileName.left(index).trimmed()
                        : fileName.trimmed();
    }

    if(singerName.isEmpty())
    {
        if(index!=-1)
        {
            singerName=fileName.mid(index+separator.size()).trimmed();
        }
        if(singerName.isEmpty())
        {
            singerName=QStringLiteral("未知歌手");
        }
    }

    if(albumName.isEmpty())
    {
        albumName=QStringLiteral("未知专辑");
    }

    qDebug()<<musicName<<" "<<singerName<<" "<<albumName<<" "<<duration;
}
