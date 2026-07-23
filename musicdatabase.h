#ifndef MUSICDATABASE_H
#define MUSICDATABASE_H

#include <QSqlDatabase>
#include <QVector>

#include "music.h"

class MusicDatabase
{
public:
    MusicDatabase();
    ~MusicDatabase();
    bool initDatabase();
    void closeDatabase();
    bool insertMusic(const Music &music);
    QVector<Music> loadAllMusic();
    bool updateMusicLike(const QString &musicId, bool isLike);
    bool updateMusicHistory(const QString &musicId,
                            bool isHistory,
                            qint64 lastPlayTime);

private:
    bool createTables();

private:
    QSqlDatabase database;
    QString connectionName;
};

#endif // MUSICDATABASE_H
