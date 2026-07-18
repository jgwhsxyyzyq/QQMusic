#include "musiclist.h"
#include "ui_listitembox.h"
#include<QMimeDatabase>
MusicList::MusicList()

{}

void MusicList::addMusicByUrl(const QList<QUrl> &urls)
{
    QMimeDatabase database;

    for (const QUrl &musicUrl : urls) {
        QMimeType mime =
            database.mimeTypeForFile(musicUrl.toLocalFile());

        if (mime.name() != "audio/mpeg" &&
            mime.name() != "audio/flac") {
            continue;
        }

        musicList.push_back(Music(musicUrl));
    }
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

