import QtQuick 2.0

// basic component that can draw itself
// to have help press  F1

Rectangle {
    id: root // for Binding
    // property | value

    color: "lightgreen"

    property string displayText: ""
//    readonly property alias internalText: _firstText
    border {
        color: "black"
        width: 1
    }

    radius: 10

    Text {
        id: _firstText
        anchors.centerIn: root
        text: root.displayText
//        x: root.width / 2 - width / 2 // current width
//        y: root.height / 2 - height / 2 // current height

//        font.pointSize: 24
//        font.bold: true
        font {
            pointSize: Math.min(root.width, root.height) / 3
            bold: true
        }
    }
}
