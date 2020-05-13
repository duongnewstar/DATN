import QtQuick 2.0
import"../Group"

Item{
    Image {
        id: statusbar
        anchors.top: parent.top
        anchors.left: parent.left
        source: "image://ImageProvider/status-bar.png"
    }
    Image {
        id: screenbgn
        anchors.top: clearbar.bottom
        anchors.left: parent.left
        source: "image://ImageProvider/bg.png"

    }
    SystemBar{
        id: systembar
        anchors.bottom: screenbgn.bottom
        anchors.left: parent.left
    }
    ClearBar{
        id: clearbar
        anchors.top: statusbar.bottom

    }
    SearchBar{
        id: searchbar
        anchors{
            left: screenbgn.left
            bottom: systembar.top
            bottomMargin: 2
        }
    }
    Tabbar{
        id:tabbar
        anchors{
            fill: screenbgn
        }
    }
    Loader{
        id: loader
        anchors.centerIn: tabbar
        source: "qrc:/Screen/YesNoScreen.qml"
        active: !Controller.clearbtn
    }
}
