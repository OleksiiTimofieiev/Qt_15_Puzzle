import QtQuick 2.12
import QtQuick.Window 2.12

// 1 50 10

// controller for timer => with some point in window;
// win and restart after each step => pop up element in qml;
// restart the game with controller => register type for qml;
// best result in panel => some file with controller;

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
