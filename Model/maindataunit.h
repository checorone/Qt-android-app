#ifndef MAINDATAUNIT_H
#define MAINDATAUNIT_H

#include<QObject>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlRecord>
#include<QtSql/QSqlQuery>

#include "DataStructures/newslistmodel.h"


class MainDataUnit : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase * db;

    static const QString insertNews;
    static const QString selectAllNews;
    static const QString createNewsTable;
    static const QString selectTables;
    static const QString selectNews_Date;

signals:
    void dataChanged(const NewsList &);
    void dataExtracted(const NewsList &);

public slots:
    void ongetNews(const QDate & from);

public:
    explicit MainDataUnit(QObject * parent);
    ~MainDataUnit();
};

#endif // MAINDATAUNIT_H
