#include "music.h"
#include "qfontinfo.h"

Music::Music(const QUrl &url)
: isLike(false)
, isHistory(false)
,musicUrl(url)

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

bool Music::getIsLike()
{
    return isLike;
}

bool Music::getIsHistory()
{
    return isHistory;
}

QString Music::getMusicName()
{
    return musicName;
}

QString Music::getSingerName()
{
    return singerName;
}

QString Music::getAlbumName()
{
    return albumName;
}

qint64 Music::getDuration()
{
    return duration;
}

QUrl Music::getMusicUrl()
{
    return musicUrl;
}

QString Music::getMusicId()
{
    return musicId;
}

void Music::parseMediaMetaData()
{


    QMediaPlayer  player;
    //加载媒体文件
    player.setMedia(QMediaContent(musicUrl));
    while (player.isMetaDataAvailable())
    {
        QCoreApplication::processEvents();
    }
    if(!player.isMetaDataAvailable())
    {
        musicName=player.metaData("Title").toString();
        singerName=player.metaData("Author").toString();
        albumName=player.metaData("AlbumTitle").toString();
        duration=player.duration();

        if(musicName.isEmpty())
        {
            musicName="未知歌曲";
        }
        if(singerName.isEmpty())
        {
            singerName="未知歌手";
        }
        if(albumName.isEmpty())
        {
            albumName="未知专辑";
        }
        qDebug()<<musicName<<" "<<singerName<<" "<<albumName<<" "<<duration;
    }

}

