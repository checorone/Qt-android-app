#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include<QObject>
#include"DataStructures/newslistmodel.h"
#include"DataStructures/gamesproperties.h"
#include"Model/mainlogicunit.h"


class ViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(NewsListModel * news READ getNewsModel NOTIFY NewsModelChanged)
    Q_PROPERTY(GameListModel * games READ getGameModel NOTIFY GameModelChanged)

private:

private:
    NewsListModel * news;
    GameListModel * games;


public:
    ViewModel();
    ~ViewModel();

public:
    NewsListModel * getNewsModel();
    GameListModel * getGameModel();

signals:
    void NewsModelChanged();
    void GameModelChanged();

    void getNews(const QDate &);


public slots:
    /*Model section*/
    void ondataChanged(const NewsList & new_news);
    void ondataExtracted(const NewsList & new_news);

    /*View section*/
    void onGameSet(int index);
    void ongetNews();

};

#endif // VIEWMODEL_H
