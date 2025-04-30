#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "editorstate.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/ui/qml/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) {
            QCoreApplication::exit(1);
        }
    }, Qt::QueuedConnection);

    qmlRegisterSingletonType<EditorState>("Models.EditorState", 1, 0, "EditorState", EditorState::singleton_provider);

    engine.load(url);

    return app.exec();
}
