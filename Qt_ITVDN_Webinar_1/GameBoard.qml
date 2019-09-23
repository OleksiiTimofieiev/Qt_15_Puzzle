import QtQuick 2.0

GridView {

//    model: //
    id: root
    model: TileModel {

    }
    // quantity of elements

    // usuallu spacing is the distance beetween elements
    cellHeight: height / 4
    cellWidth: width / 4

    delegate: Item {
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        visible: display != 16

        Tile {
            // role:
            displayText: display
            anchors.fill: _backgroundDelegate
            anchors.margins: 5
        }
    }


}
