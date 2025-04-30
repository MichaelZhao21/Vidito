#include "editorstate.h"

EditorState::EditorState() : project_path("None") {}

EditorState &EditorState::get_instance()
{
    static EditorState instance;
    return instance;
}

QObject *EditorState::singleton_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    EditorState *instance = &get_instance();
    return instance;
}

QString EditorState::get_project_path() const
{
    return QString::fromUtf8(project_path);
}

void EditorState::set_project_path(const QUrl &path)
{
    project_path = path.path().toStdString();
    emit project_path_changed(project_path);
}
