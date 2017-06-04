#include "maindataunit.h"
#include <QDebug>
#include <QSqlError>

const QString MainDataUnit::insertNews = "INSERT INTO news_table(label, shorttext, fulltext, picture, date, game, link) "
                                         "VALUES (:label, :shorttext, :fulltext, :picture, :date, :game, :link);";

const QString MainDataUnit::selectAllNews = "SELECT * FROM news_table;";

const QString MainDataUnit::selectNews_Date = "SELECT * FROM news_table "
                                              "WHERE date='%1';";

const QString MainDataUnit::createNewsTable = "CREATE TABLE IF NOT EXISTS news_table ("
                                              "label TEXT, "
                                              "shorttext TEXT, "
                                              "fulltext TEXT, "
                                              "picture BLOB, "
                                              "date TEXT, "
                                              "game TEXT, "
                                              "link TEXT PRIMARY KEY NOT NULL"
                                              ");";

const QString MainDataUnit::selectTables = "SELECT name FROM sqlite_master "
                                           "WHERE type='table' "
                                           "ORDER BY name;";


MainDataUnit::MainDataUnit(QObject *parent) : QObject(parent)
{
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("ESA_database.sqlite");

    if(!db->open())
    {
        qDebug() << "Could not access the database: " << db->lastError().text();
    }


    /*Check existing tables and create tables that do not exist but needed*/
    QSqlQuery query = QSqlQuery(*db);
    if (!query.exec(createNewsTable))
    {
        qDebug() << "Could not create table: " << query.lastError().text();
    }



    qDebug() << "=====================\n"
             << "State of database:\n"
             << "Opened: "  << db->open() << endl
             << "Options: " << db->connectOptions() << endl
             << "Name: " << db->connectionName() << endl
             << "=====================\n";

//    for(int i = 0; i < 25; i++)
//    {
//        query.prepare(insertNews);
//        query.bindValue(":label", QString("Qt и SQLite и вообще, программирование БД в Qt"));
//        query.bindValue(":shorttext", QString("Об этих двух замечательных продуктах можно прочитать следуя приведенным выше ссылкам, а мы будем конкретно рассматривать программирование БД в Qt, в частности, на примере SQLite. Скажу только, что SQLite несколько отличается от «обычных» баз данных, таких как MySQL тем, что «не обладает» клиент-серверной архитектурой. То есть движок БД не является отдельно работающим процессом, с которым взаимодействует программа. SQLite представляет собой библиотеку, с которой компонуется ваша программа и, таким образом, движок становится составной частью программы. То есть представьте вы решили сохранять все данные, с которыми «сталкивается» ваша программа в обычный файл. В один прекрасный день вы решаете сохранять данные в файле, но организовав это с «реляционной» точки зрения. После этого вы поняли, что новая структура файла должна «распознаваться особым образом». С этого, как минимум, следует, что вам нужно предоставить некоторый API, обеспечивающий связь между этим файлом данных с приложением. В общем, следуя логической постановке приведенного сценария у вас рождается система БД, не требующая сервера БД и собственно, клиента. Получается достаточно быстрая по сравнению с «клиент-серверной» БД система, и сама программа упрощается."));
//        query.bindValue(":fulltext", QString("QSqlDriver является абстрактным базовым классом, предназначенный для доступа к специфичным БД. Важно, что класс не должен быть использован «прямо», взамен нужно/можно воспользоваться QSqlDatabase. Хотя, если вы хотите создать свой собственный драйвер SQL, то можете наследовать от QSqlDriver и реализовать чисто виртуальные, и нужные вам виртуальные функции."));
//        query.bindValue(":picture", QByteArray());
//        query.bindValue(":date", QDate::currentDate().toString("dd::MM::yyyy"));
//        query.bindValue(":game", QString("Dota 2"));
//        query.bindValue(":link", QString("https://habrahabr.ru/post/128836/") + QString::number(i));
//        query.exec();
//    }


}

MainDataUnit::~MainDataUnit()
{
    db->close();
    delete db;
}




void MainDataUnit::ongetNews(const QDate & from)
{
    QSqlQuery query = QSqlQuery(*db);
    NewsList list;

    for(int i = 0; i < 38; i++) // Get news for the three past days
    {
        query.exec(selectNews_Date.arg(from.addDays(-i).toString("dd::MM::yyyy")));

        if(!query.isActive())
        {
            qDebug() << "News with date: " << from.addDays(-i).toString("dd::MM::yyyy") << " does not exist\n";
        }

        QSqlRecord rec = query.record();
        while (query.next())
        {
            /*Image extraction section*/
            QByteArray outByteArray = query.value(rec.indexOf("picture")).toByteArray();
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData(outByteArray);

            /*Date extraction section*/
            QDate outDate = QDate();
            outDate.fromString(query.value(rec.indexOf("date")).toString(), QString("dd::MM::yyyy"));


            list.append(News(query.value(rec.indexOf("label")).toString(),
                             query.value(rec.indexOf("shorttext")).toString(),
                             query.value(rec.indexOf("fulltext")).toString(),
                             outPixmap,
                             outDate,
                             query.value(rec.indexOf("game")).toString(),
                             query.value(rec.indexOf("link")).toString()));
        }
    }

    emit dataExtracted(list);
    qDebug() << "Emited dataExtracted from MDU\n";
}

