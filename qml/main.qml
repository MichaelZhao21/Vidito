import QtCore
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtQuick.Dialogs
import Models.EditorState 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Vidito"

    ColumnLayout {
        width: parent.width
        anchors.margins: 20
        spacing: 10

        Text {
            Layout.alignment: Qt.AlignHCenter
            text: "Vidito"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            Layout.alignment: Qt.AlignHCenter
            text: "Open a file or create a new project"
            font.pixelSize: 16
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Open Project"
            onClicked: openFileDialog.open()
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Create New Project"
            onClicked: createFileDialog.open()
        }

        FileDialog {
            id: openFileDialog
            title: "Open Project"
            nameFilters: ["Vidito Project (*.vidito)"]
            currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
            onAccepted: {
                if (selectedFile) {
                    EditorState.projectPath = selectedFile
                }
            }
        }

        FileDialog {
            id: createFileDialog
            title: "Create New Project"
            nameFilters: ["Vidito Project (*.vidito)"]
            currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
            fileMode: FileDialog.SaveFile
            onAccepted: {
                if (selectedFile) {
                    EditorState.projectPath = selectedFile
                }
            }
        }

        Text {
            Layout.alignment: Qt.AlignHCenter
            text: "File: " + EditorState.projectPath
            font.pixelSize: 16
        }
    }
}
