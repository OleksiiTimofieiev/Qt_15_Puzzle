import QtQuick 2.12
import QtQuick.Window 2.12

// 1 50 10

Window {
    id: root // for Binding
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // Component is named by the name of its file;

    // better to use binding (to the size of the window)

    GameBoard {
        anchors.fill: parent
    }
}
