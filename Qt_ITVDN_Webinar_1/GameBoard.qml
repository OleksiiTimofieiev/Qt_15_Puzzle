import QtQuick 2.0
import Game 1.0;

GridView {

//    model: //
    id: root
    model: GameBoardModel {

    }

    // usually spacing is the distance beetween elements
    cellHeight: height / 4
    cellWidth: width / 4

    // delegate visualizes date in the current context;

    delegate: Item { // item to have spacing
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        visible: display != 16 // not to show 16 element

        Tile {
            // role:
            displayText: display

            anchors.fill: _backgroundDelegate
            anchors.margins: 5
        }
    }


}
