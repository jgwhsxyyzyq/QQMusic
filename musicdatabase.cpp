#include "musicdatabase.h"
#include<QDebug>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
MusicDatabase::MusicDatabase()
    :connectionName("qqmusic_connection")
{}

MusicDatabase::~MusicDatabase()
{
    closeDatabase();
}

bool MusicDatabase::initDatabase()
{
    //1.检查驱动是否存在
    if(!QSqlDatabase::isDriverAvailable("QSQLITE"))
    {
        qDebug()<<"驱动不存在";
        qDebug() << "当前可用驱动："
                 << QSqlDatabase::drivers();
        return false;
    }


    // 2. 获取数据库保存目录
    QString dataDirectory=QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if(dataDirectory.isEmpty())
    {
        qDebug()<<"无法获取数据目录"<< dataDirectory;
        return false;
    }

    // 3. 创建数据库目录

    if(!QDir().mkpath(dataDirectory))
    {
        qDebug()<<"创建数据库目录失败";
        return false;
    }

    // 4. 生成qqmusic.db文件路径
    QDir dataDir(dataDirectory);
    QString databasePath=dataDir.filePath("qqmusic.db");
    qDebug() << "数据库文件路径："
             << databasePath;

    // 5. 创建SQLite连接
    if(QSqlDatabase::contains(connectionName))
    {
        database=QSqlDatabase::database(connectionName);


    }
    else{
        database=QSqlDatabase::addDatabase("QSQLITE",connectionName);
    }
    // 6. 设置数据库文件路径
    database.setDatabaseName(databasePath);
    // 7. 打开数据库
    if(!database.open())
    {
        qDebug()<<"打开数据库失败"<<database.lastError().text();
        return false;
    }

    qDebug()<<"数据库连接成功";
    if(!createTables())
    {
        qDebug()<<"数据库表初始化失败";
        database.close();
        return false;
    }
    return true;

}

void MusicDatabase::closeDatabase()
{
    if(database.isOpen())
    {
        database.close();
    }
}

bool MusicDatabase::insertMusic(const Music &music)
{
    // 1. 确认数据库已经打开
    if(!database.isOpen())
    {
        qDebug
            () << "数据库未打开，无法添加歌曲";
        return false;
    }
     // 2. 创建查询对象，并指定使用当前数据库连接
    QSqlQuery query(database);
    // 3. 准备插入SQL
query.prepare(R"(
        INSERT OR IGNORE INTO music
        (
            music_id,
            file_path,
            music_name,
            singer_name,
            album_name,
            duration,
            is_like,
            is_history,
            last_play_time
        )
        VALUES
        (
            :music_id,
            :file_path,
            :music_name,
            :singer_name,
            :album_name,
            :duration,
            :is_like,
            :is_history,
            :last_play_time
        )
    )");
     // 4. 将Music对象的数据绑定到SQL参数
    query.bindValue(":music_id",music.getMusicId());

    query.bindValue(":file_path",music.getMusicUrl().toLocalFile());

    query.bindValue(":music_name",music.getMusicName());

    query.bindValue(":singer_name",music.getSingerName());

    query.bindValue(":album_name",music.getAlbumName());

    query.bindValue(":duration",music.getDuration());

    query.bindValue(":is_like",music.getIsLike()?1:0);

    query.bindValue(":is_history",music.getIsHistory()?1:0);

    query.bindValue(":last_play_time", music.getLastPlayTime());
    // 5. 执行SQL
    if(!query.exec())
    {
    qDebug()<< "添加歌曲到数据库失败"<<query.lastError().text();
        return false;
    }
    if(query.numRowsAffected()==0)
    {
        qDebug() << "数据库中已经存在该歌曲："
                 << music.getMusicUrl().toLocalFile();
    }
    else{
        qDebug() << "歌曲添加成功："
                 << music.getMusicUrl().toLocalFile();
    }
    return true;
}

QVector<Music> MusicDatabase::loadAllMusic()
{
    QVector<Music> result;
    //1检查数据库是否打开
    if(!database.isOpen())
    {
        qDebug()<<"数据库未打开";
        return result;
    }
    //2创建查询对象
    QSqlQuery query(database);
    if(!query.exec(R"(
        SELECT
            music_id,
            file_path,
            music_name,
            singer_name,
            album_name,
            duration,
            is_like,
            is_history,
            last_play_time
        FROM music
    )"))
    {
        qDebug() << "读取歌曲失败："
                 << query.lastError().text();
        return result;
    }

    while(query.next())
    {
        Music music;

        music.setMusicId(query.value(0).toString());

        music.setMusicUrl(
            QUrl::fromLocalFile(query.value(1).toString())
            );

        music.setMusicName(query.value(2).toString());
        music.setSingerName(query.value(3).toString());
        music.setAlbumName(query.value(4).toString());
        music.setDuration(query.value(5).toLongLong());

        music.setIsLike(query.value(6).toInt() != 0);
        music.setIsHistory(query.value(7).toInt() != 0);
        music.setLastPlayTime(query.value(8).toLongLong());
        result.push_back(music);
    }
     qDebug() << "从数据库加载歌曲数量：" << result.size();
    return result;
}

bool MusicDatabase::updateMusicLike(const QString &musicId, bool isLike)
{
    if(!database.isOpen())
    {
        qDebug()<<"数据库未打开，无法更新收藏状态";
        return false;
    }

    QSqlQuery query(database);
    query.prepare(R"(
        UPDATE music
        SET is_like = :is_like
        WHERE music_id = :music_id
    )");
    query.bindValue(":is_like",isLike ? 1 : 0);
    query.bindValue(":music_id",musicId);

    if(!query.exec())
    {
        qDebug()<<"更新收藏状态失败："<<query.lastError().text();
        return false;
    }

    return true;
}

bool MusicDatabase::updateMusicHistory(const QString &musicId,
                                       bool isHistory,
                                       qint64 lastPlayTime)
{
    if(!database.isOpen())
    {
        qDebug()<<"数据库未打开，无法更新播放历史";
        return false;
    }

    QSqlQuery query(database);
    query.prepare(R"(
        UPDATE music
        SET is_history = :is_history,
            last_play_time = :last_play_time
        WHERE music_id = :music_id
    )");
    query.bindValue(":is_history",isHistory ? 1 : 0);
    query.bindValue(":last_play_time",lastPlayTime);
    query.bindValue(":music_id",musicId);

    if(!query.exec())
    {
        qDebug()<<"更新播放历史失败："<<query.lastError().text();
        return false;
    }

    return true;
}

bool MusicDatabase::createTables()
{
    // 1. 创建QSqlQuery对象，使用database连接
    QSqlQuery query(database);
    // 2. 创建保存建表SQL的QString
    QString createMusicTable=R"(

    CREATE TABLE IF NOT EXISTS music(
            music_id       TEXT PRIMARY KEY,
            file_path      TEXT UNIQUE NOT NULL,
            music_name     TEXT,
            singer_name    TEXT,
            album_name     TEXT,
            duration       INTEGER DEFAULT 0,
            is_like        INTEGER DEFAULT 0,
            is_history     INTEGER DEFAULT 0,
            last_play_time INTEGER DEFAULT 0


)
)";
    // 3. 使用query.exec()执行SQL
    // 4. 执行失败时输出query.lastError().text()
    if(!query.exec(createMusicTable))
    {
        qDebug()<<"创建music表失败"<<query.lastError().text();
        return false;

    }
     // 5. 成功时返回true
    qDebug() << "数据库表初始化完成";
    return true;
}
