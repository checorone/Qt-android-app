import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0


ToolBar {
    id:bar

    background: Rectangle {
        width: bar.width
        height: bar.height

        Image {
        source: "../resources/bar.png"
        }
    }

    layer.enabled: true
    layer.effect: DropShadow {
        verticalOffset: 3
        radius: 8.0
        samples: 16
        color: "#80000000"
    }

    RowLayout {
        anchors.fill: parent

        /*Back Button, appears when stack
        have greater than one page*/
        ToolButton {
            Image {
                id: backButton
                source: "../resources/back-icon.png"

                width: parent.width * 0.66
                height: parent.height * 0.66

                anchors.centerIn: parent
            }
            visible: stack.depth > 1
            onClicked: stack.pop()
        }

        /*Menu button, appears when stack
        have only one page*/
        ToolButton {
            Image {
                id: menuButton
                source: "../resources/hamb-icon.png"

                smooth: true
                width: parent.width * 0.66
                height: parent.height * 0.66

                anchors.centerIn: parent
            }

            visible: stack.depth === 1
            onClicked: drawer.open()
        }

//        Item { Layout.fillWidth: true }

//        Image {
//            id: csgoLogo
//            source: "../resources/csgo.png"

//            width: parent.width * 0.66
//            height: parent.height * 0.66
//        }

        /*Space between buttons*/
        Item { Layout.fillWidth: true }

        /*Refresh button*/
        ToolButton {
            Image {
                id: settingsButton
                source: "../resources/hamb-settings-icon.png"
                smooth: true
                width: parent.width * 0.66
                height: parent.height * 0.66

                anchors.centerIn: parent


            }
            visible: stack.depth === 1
            onClicked: popup.open()
        }
    }

    Popup {
             id: popup
             x: settingsButton.x + wd.width * 0.3
             y: settingsButton.y + 50
             width: bar.height * 4
             height: bar.height * 3
             modal: true
             focus: true
             closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

             padding: 10

             ListView {
                 id: view
                 model: VM.games

                 anchors.fill: parent

                 delegate: SwitchDelegate {
                     width: parent.width
                     height: 40
                     id: sw
                     text: model.name
                     checked: model.activated

                     onClicked: wd.reSet(index)
                 }

             }
         }
}




