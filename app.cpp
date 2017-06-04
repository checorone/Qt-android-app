#include "app.h"

App::App() : vm(new ViewModel), mlu(new MainLogicUnit), engine(new QQmlApplicationEngine())
{

}


App::~App()
{
    delete  vm;
    delete  mlu;
    delete engine;
}

void App::initLinks()
{
    QObject::connect(vm,SIGNAL(getNews(const QDate &)),mlu, SLOT(ongetNews(const QDate &)));
    QObject::connect(mlu,SIGNAL(dataChanged(const NewsList &)),vm, SLOT(ondataChanged(const NewsList &)));
    QObject::connect(mlu,SIGNAL(dataExtracted(const NewsList &)),vm, SLOT(ondataExtracted(const NewsList &)));
    QObject::connect(engine->rootObjects()[0],SIGNAL(reSet(int)),vm, SLOT(onGameSet(int)));
    QObject::connect(engine->rootObjects()[0],SIGNAL(getNews()),vm, SLOT(ongetNews()));

    started = true;

    vm->ongetNews();
}

void App::initQML()
{
    engine->rootContext()->setContextProperty("VM", vm);
    qmlRegisterType<ViewModel>("ViewModel", 1, 0, "ViewModel");
    engine->load(QUrl(QStringLiteral("qrc:/view/main.qml")));
}
