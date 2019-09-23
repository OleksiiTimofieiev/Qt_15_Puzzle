import QtQuick 2.0
import Game 1.0;

GridView {

//    model: //
    id: root
    model: GameBoardModel {

    }

    // usually spacing is the distance beetween elements
    cellHeight: height / root.model.dimension
    cellWidth: width / root.model.dimension

    // delegate visualizes date in the current context;

    delegate: Item { // item to have spacing
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        visible: display !== root.model.hiddenElementValue // not to show 16 element

        Tile {
            // role:
            displayText: display

            anchors.fill: _backgroundDelegate
            anchors.margins: 5
            // in order to handle mouse input
            MouseArea {
                // set to the parent
                anchors.fill: parent
                onClicked: {
                    root.model.move(index); // index is attached property
                }
            }
        }
    }


}
