#include <QApplication>
#include "app.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    App a;
    a.initQML();
    a.initLinks();

    return app.exec();
}
