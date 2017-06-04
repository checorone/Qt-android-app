#ifndef APP_H
#define APP_H

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>

#include "ViewModel/viewmodel.h"
#include "Model/mainlogicunit.h"


class App
{
private:
     ViewModel * vm;
     MainLogicUnit * mlu;
     QQmlApplicationEngine * engine;

     bool started;

public:
    App();
    ~App();

    void initLinks();
    void initQML();


};

#endif // APP_H
