import QtQuick 2.0
import "../Component"
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.2
import QtQuick.Controls 1.2

Rectangle{
    width: 360
    height: 30
    radius: 5
    BaseButton{
        id: searchbtn
        width: 30
        height: 30
        source: "image://ImageProvider/searchIcon.png"
        anchors.right: parent.right
        anchors.top: parent.top
        onBtnClicked: {
           filterModel.setFilterString(txt.text);
        }
    }
//    Rectangle{
//        width: 330
//        height: 30
//        radius: 5
//        TextInput{
//            anchors.fill: parent
//            font.pixelSize: 30

//        }
        TextField {
            id: txt
            placeholderText: "Type here.."
            Layout.fillWidth: true
            font.pointSize: 12
            style: TextFieldStyle {
                textColor: "black"
                background: Rectangle {
                    radius: 5
                    implicitWidth: 330
                    implicitHeight: 30
//                    border.color: "#6bdce4"
//                    border.width: 1
                }
            }
            onTextChanged: {
                filterModel.setFilterString(text);
            }
        }
    }
//}
