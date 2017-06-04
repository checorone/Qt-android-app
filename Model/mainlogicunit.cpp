#include "mainlogicunit.h"
#include <QDebug>

MainLogicUnit::MainLogicUnit(QObject * parent) : QObject(parent)
{
    MDU = new MainDataUnit(this);
    MNU = new MainNetworkUnit(this);

    connect(this, SIGNAL(getNews(const QDate &)), MDU, SLOT(ongetNews(const QDate &)));

    connect(MDU, SIGNAL(dataChanged(const NewsList &)), this, SLOT(ondataChanged(const NewsList &)));
    connect(MDU, SIGNAL(dataExtracted(const NewsList &)), this, SLOT(ondataExtracted(const NewsList &)));
}

MainLogicUnit::~MainLogicUnit()
{
    delete MDU;
    delete MNU;
}

void MainLogicUnit::ongetNews(const QDate & from)
{
    emit getNews(from);
    qDebug() << "Emited getNews from MLU\n";
}

void MainLogicUnit::ondataChanged(const NewsList & news)
{
    emit dataChanged(news);
}

void MainLogicUnit::ondataExtracted(const NewsList & news)
{
    if(news.isEmpty())
        //Send request on news in network unit
        ;
    else
        emit dataExtracted(news);
    qDebug() << "Emited dataExtracted from MLU\n";
}
