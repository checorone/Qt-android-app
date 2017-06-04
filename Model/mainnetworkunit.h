#ifndef MAINNETWORKUNIT_H
#define MAINNETWORKUNIT_H

#include <QObject>

class MainNetworkUnit : public QObject
{
    Q_OBJECT
public:
    explicit MainNetworkUnit(QObject * parent);
};

#endif // MAINNETWORKUNIT_H
