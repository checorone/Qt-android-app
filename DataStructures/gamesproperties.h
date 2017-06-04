#ifndef GAMESPROPERTIES_H
#define GAMESPROPERTIES_H

#include<QAbstractListModel>


typedef QList<QPair<QString, bool>> GameList;

class GameListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    GameList m_data;

    enum Roles
    {
        NameRole = Qt::DisplayRole,
        ActivatedRole = Qt::UserRole + 1
    };

public:
    explicit GameListModel(QObject *parent = 0);
    virtual ~GameListModel();

public: /*User-defined methods*/
    void ReSet(QModelIndex  index);
    GameList getProperties() const;

public: /*Reimplemented methods*/
    virtual int rowCount(const QModelIndex &parent) const override final;
    virtual QVariant data(const QModelIndex &index, int role) const override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

signals:
    void dataChanged();

public slots:
};

#endif // GAMESPROPERTIES_H
