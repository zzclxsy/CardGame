#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./GameContorl/JHGameContorl.h"
#include "JHFramework.h"
#include "Player/JHPlayer.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    JHFramework framework;
    framework.SetQmlEngine(&engine);
    framework.AddModule("JHAppData", new JHAppData);
    framework.AddModule("JHCardManager", new JHCardManager);
    framework.AddModule("JHLandlordsRule", new JHLandlordsRule);

    engine.rootContext()->setContextProperty("app", &framework);;
    qmlRegisterType<JHPlayer>("JHFramework",1,0,"JHPlayer");

    const QUrl url(QStringLiteral("qrc:/JHLandlord/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
