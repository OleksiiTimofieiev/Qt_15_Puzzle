import QtQuick 2.0

GridView {

//    model: //
    id: root
    model: TileModel {

    }
        // quantity of elements
    cellHeight: height / 4
    cellWidth: width / 4

    delegate: Tile {
        displayText: display
        width: root.cellWidth
        height: root.cellHeight
    }
}
