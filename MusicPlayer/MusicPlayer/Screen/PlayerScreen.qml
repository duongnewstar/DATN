import QtQuick 2.0
import "../Group"
import AppEnums 1.0

Item{
    id: playerscreen
    Image {
        id: statusbar
        anchors.top: parent.top
        anchors.left: parent.left
        source: "image://ImageProvider/status-bar.png"
    }
    Image {
        id: screenbgn
        anchors.top: statusbar.bottom
        anchors.left: parent.left
        source: "image://ImageProvider/bg.png"

    }
    SystemBar{
        id: systembar
        anchors.top: screenbgn.bottom
        anchors.left: parent.left
    }
    MenuBar{
        id: menubar
        anchors.top: screenbgn.top
    }
    PlayerBtnBar{
        id: playerbtnbar
        anchors.bottom: systembar.top
    }
    MusicTimeBar{
        id: musictimebar
        anchors{
            bottom: playerbtnbar.top
            left: statusbar.left
            leftMargin: 19
        }
    }
    RunningTextBar{
        id: runningtextbar
        anchors{
            bottom: musictimebar.top
            left: statusbar.left
            leftMargin: 20
        }
    }
    VolumeBar{
        id: volumebar
        anchors{
            bottom: musictimebar.top
            bottomMargin: 20
            right: musictimebar.right
            rightMargin: 20
        }
    }  
    CdGroup{
        id: cdgroup
        anchors{
            top: menubar.bottom
            topMargin: 10
            left: playerscreen.left
            leftMargin: -159
        }
    }
    RotorGroup{
        id:rotorgroup
        anchors{
            right: musictimebar.right
            top: menubar.bottom
            topMargin: 10
        }
    }
}
