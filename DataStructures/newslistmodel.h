#ifndef NEWSLISTMODEL_H
#define NEWSLISTMODEL_H

#include <QAbstractListModel>

#include"news.h"

typedef QList<News> NewsList;

class NewsListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    NewsList m_data;
    
    enum Roles
    {
        shortTextRole = Qt::DisplayRole,
        PictureRole = Qt::DecorationRole,
        LabelRole = Qt::UserRole + 1,
        fullTextRole = Qt::UserRole + 2,
        DateRole = Qt::UserRole + 3,
        GameRole = Qt::UserRole + 4,
        LinkRole = Qt::UserRole + 5
    };
    
public:
    explicit NewsListModel(QObject *parent = 0);
    virtual ~NewsListModel();
    
public: /*User-defined methods*/  
    void append(const NewsList & items);
    void clear();
    News last() const;
    News first() const;


public: /*Reimplemented methods*/
    virtual int rowCount(const QModelIndex &parent) const override final;
    virtual QVariant data(const QModelIndex &index, int role) const override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

signals:
    void dataChanged();

public slots:
};

#endif
