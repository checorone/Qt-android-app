#ifndef MAINLOGICUNIT_H
#define MAINLOGICUNIT_H

#include<QObject>

#include"DataStructures/newslistmodel.h"

#include"maindataunit.h"
#include"mainnetworkunit.h"

class MainLogicUnit : public QObject
{
    Q_OBJECT

private:
    MainDataUnit * MDU;
    MainNetworkUnit * MNU;

public:
    explicit MainLogicUnit(QObject * parent = nullptr);
    ~MainLogicUnit();

signals:
    void dataChanged(const NewsList &);
    void dataExtracted(const NewsList &);

    void getNews(const QDate &);

public slots:
    void ongetNews(const QDate &);

    void ondataChanged(const NewsList &);
    void ondataExtracted(const NewsList &);
};

#endif // MODEL_H
