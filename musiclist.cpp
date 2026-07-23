#include "musiclist.h"
#include "ui_listitembox.h"
#include<QMimeDatabase>
MusicList::MusicList()

{}

void MusicList::addMusicByUrl(const QList<QUrl> &urls)
{
    QMimeDatabase database;

    for (const QUrl &musicUrl : urls) {
        //同一个本地文件只允许添加一次
        if(containsMusicUrl(musicUrl))
        {
            continue;
        }

        QMimeType mime =
            database.mimeTypeForFile(musicUrl.toLocalFile());

        if (mime.name() != "audio/mpeg" &&
            mime.name() != "audio/flac") {
            continue;
        }

        musicList.push_back(Music(musicUrl));
    }
}

void MusicList::addMusic(const Music &music)
{
    if(music.getMusicUrl().isEmpty()
        || containsMusicUrl(music.getMusicUrl()))
    {
        return;
    }

    musicList.push_back(music);
}

bool MusicList::containsMusicUrl(const QUrl &musicUrl)
{
    for(Music &music : musicList)
    {
        if(music.getMusicUrl()==musicUrl)
        {
            return true;
        }
    }

    return false;
}



MusicList::iterator MusicList::findMusicById(const QString &musicId)
{
    for(iterator it=begin();it!=end();it++)
    {
        if(it->getMusicId()==musicId)
        {
            return it;
        }
    }
    return end();
}

MusicList::iterator MusicList::end()
{
    return musicList.end();
}

MusicList::iterator MusicList::begin()
{
    return musicList.begin();
}

