import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../Component"
Item {
    id: tabbarbgn
    TabBar{
        id: tabbar
        width: tabbarbgn.width
        TabButton {
            text: qsTr("FOLDER")+QmlTranslator.emptytxt
        }
        TabButton {
            text: qsTr("ALBUM")+QmlTranslator.emptytxt
        }
        TabButton {
            text: qsTr("ARSTIST")+QmlTranslator.emptytxt
        }
        TabButton {
            text: qsTr("TRACK")+QmlTranslator.emptytxt
        }
    }
    StackLayout {
        width: parent.width
        currentIndex: tabbar.currentIndex
        Item {
            id: folderTab
            Rectangle{
                width: 480
                height: 220
                anchors{
                    top: folderTab.top
                    topMargin: 45
                }
            }
        }
        Item {
            id: albumTab
            Rectangle{
                width: 480
                height: 220
                anchors{
                    top: albumTab.top
                    topMargin: 45
                }
            }
        }
        Item {
            id: artistTab
            Rectangle{
                width: 480
                height: 220
                anchors{
                    top: artistTab.top
                    topMargin: 45
                }
            }
        }
        Item
        {
            id: trackTab

            Rectangle{
                id: rec
                width: 480
                height: 220
                clip: true
                color: "#6bdce4"
                anchors{
                    top: trackTab.top
                    topMargin: 45
                }

                ListView {
                    id: listSong
                    anchors.fill: parent
                    anchors.left: parent.left
                    spacing: 5
                    model: filterModel
                    //                    model: SongModel
                    focus: true
                    property string songPath: ""
                    property int indexTemp: 0
                    delegate:
                        RunningText {
                        id: rTxt1
                        text: name
                        font.pixelSize: 20
                        Rectangle{
                            z:-1
                            height:25
                            width:1000
                            anchors{
                                top: parent.top
                                left: parent.left

                            }
                            color: Qt.lighter("#6bdce4", 0.8)
                        }
                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                listSong.currentItem.color = "black"
                                anim.stop()
                                listSong.currentItem.x = 0

                                listSong.currentIndex = index

                                listSong.songPath= ""
                                listSong.songPath = path + name
                                listSong.indexTemp = index
                                SongModel.getCurrentSongIndex(listSong.currentItem.text)

                            }
                            //                            onDoubleClicked: {
                            //                                console.log(listSong.currentIndex)
                            //                                Controller.playSelectedSong(listSong.currentIndex)
                            //                            }
                        }
                    }

                    onSongPathChanged:{
                        console.log("path:");
                        console.log(listSong.songPath);
                        console.log("tmp=",listSong.indexTemp)
                        listSong.currentItem.color = "red"
                        anim.start()
                    }

                    PropertyAnimation{id: anim; target:listSong.currentItem ; property: "x"; from: 0; to:  listSong.currentItem.des; duration: listSong.currentItem.dur; loops: Animation.Infinite;}

                    Component.onCompleted: {
                        listSong.currentItem.color = "red"
                        filterModel.setSortOrder(false)
                    }
                    Connections{
                        target: SongModel
                        onCurrentItemRemoved:{
                            filterModel.clear(listSong.currentIndex)
                            if(index==0){
                                listSong.currentIndex=index+1
                            }
                            else if(index==listSong.count){
                                listSong.currentIndex=index-1
                            }
                            else{
                                listSong.currentIndex=index+1
                            }
                        }
                    }
                }
                Scrollsearch{
                    anchors{
                        top: rec.top
                        right: rec.right
                    }
                }
            }

        }
    }
}
