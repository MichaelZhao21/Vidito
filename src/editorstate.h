#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include <QObject>
#include <QtQml>
#include <string>

class EditorState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString projectPath READ get_project_path WRITE set_project_path NOTIFY project_path_changed)
    QML_ELEMENT
    QML_SINGLETON
public:
    static EditorState &get_instance();
    static QObject *singleton_provider(QQmlEngine *, QJSEngine *);

    QString get_project_path() const;
    void set_project_path(const QUrl &);

private:
    EditorState();
    EditorState(EditorState const &);    // Don't implement
    void operator=(EditorState const &); // Don't implement

    std::string project_path;

signals:
    void project_path_changed(std::string project_path);
};

#endif // EDITORSTATE_H
