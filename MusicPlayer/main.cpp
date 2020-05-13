#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "resourceimageprovider.h"
#include "playercontroller.h"
#include "screencontroller.h"
#include "screenmodel.h"
#include "appdefines.h"
#include "appengine.h"
#include "qmltranslator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    //    AppEngine::getInstance();
    //    AppEngine::getInstance()->initialize(&app);

    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("ImageProvider"), new ResourceImageProvider(QQuickImageProvider::Image));
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    Playercontroller objA;
    engine.rootContext()->setContextProperty("Controller", &objA);
    SongModel model;

    QObject::connect(&objA,SIGNAL(list_music1(QString)),&model,SLOT(list_music(QString)));
//    QObject::connect(&model,SIGNAL(currentItemRemoved(int)),&objA,SLOT(removeCurrentItem(int)));
    engine.rootContext()->setContextProperty("SongModel",&model);
    Song song1("aaa");
    model.addSong(song1);
    Song song2("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
    FilterProxyModel filterModel;
//    QObject::connect(&model,SIGNAL(currentItemRemoved(int)),&filterModel,SLOT(clear(int)));
    filterModel.setSourceModel(&model);
    model.addSong(song2);
    filterModel.setFilterRole(name);
    filterModel.setSortRole(name);
    engine.rootContext()->setContextProperty("filterModel", &filterModel);

    Qmltranslator qmltranslator;
    engine.rootContext()->setContextProperty("QmlTranslator", &qmltranslator);

    qmlRegisterType<AppEnums>("AppEnums", 1, 0, "AppEnums");


    ScreenController::getInstance();
    ScreenController::getInstance()->initialize(engine.rootContext());
    ScreenController::getInstance()->initializeScreen(&engine);
    //    engine.load(url);


    return app.exec();
}
