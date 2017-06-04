#include "gamesproperties.h"

#include "newslistmodel.h"

GameListModel::GameListModel(QObject *parent) : QAbstractListModel(parent)
{
    m_data.append(QPair<QString, bool>("CS:GO", 1));
    m_data.append(QPair<QString, bool>("Dota 2", 1));
    m_data.append(QPair<QString, bool>("LOL", 1));
}

GameListModel::~GameListModel()
{

}

void GameListModel::ReSet(QModelIndex index)
{

    auto temp = m_data.at(index.row());
    if (m_data.at(index.row()).second == 1)
    {
        temp.second = 0;

    }
    else
        temp.second = 1;
    m_data.replace(index.row(), temp);
    emit dataChanged();

}

GameList GameListModel::getProperties() const
{
    return m_data;
}


int GameListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant GameListModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() == false)
        return QVariant();

    if(index.row() < 0 || index.row() >= m_data.count())
        return QVariant();

    switch (role)
    {
    case NameRole:
        return m_data.at(index.row()).first;
    case ActivatedRole:
        return  m_data.at(index.row()).second;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> GameListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ActivatedRole] = "activated";
    return roles;
}
