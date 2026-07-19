#ifndef MUSICLIST_H
#define MUSICLIST_H
#include "music.h"
#include "qurl.h"
#include <QVector>

class MusicList
{


public:
    MusicList();
    void addMusicByUrl(const QList<QUrl>& urls);
    typedef typename QVector<Music>::iterator iterator;
    iterator begin();
    iterator end();
    iterator findMusicById(const QString& musicId);


private:
    bool containsMusicUrl(const QUrl& musicUrl);
    QVector<Music> musicList;
};

#endif // MUSICLIST_H
