#include "viewmodel.h"
#include <QDebug>

ViewModel::ViewModel()
{
    news = new NewsListModel(this);
    games = new GameListModel(this);

}

ViewModel::~ViewModel()
{
    delete news;
    delete games;
}

NewsListModel * ViewModel::getNewsModel()
{
    return news;
}

GameListModel * ViewModel::getGameModel()
{
    return games;
}



void ViewModel::ondataChanged(const NewsList &new_news)
{
    news->clear();
    news->append(new_news);
    emit NewsModelChanged();
}

void ViewModel::ondataExtracted(const NewsList &new_news)
{
    news->append(new_news);
    emit NewsModelChanged();
    qDebug() << "News added to vm\n";
}

void ViewModel::onGameSet(int index)
{
    games->ReSet(games->sibling(index, 0 , QModelIndex()));
}

void ViewModel::ongetNews()
{
    emit getNews(news->last().getDate());
    qDebug() << "Emited getNews from vm\n";
}
