import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Drawer {
    id: drawerLocal

    width: 0.7 * wd.width
    height: wd.height

    ColumnLayout {
        anchors.fill: parent

        Rectangle {
            id: logo
            Layout.fillWidth: true
            height: parent.height * 0.2
            color: "#00000000"

            Image {
                source: "../resources/esports.png"
                height: parent.height
                width: parent.height * 1.5
                anchors.centerIn: parent
                smooth: true

                layer.enabled: true
                layer.effect: DropShadow {
                    horizontalOffset: 3
                    verticalOffset: 3
                    radius: 4.0
                    samples: 8
                    color: "#000000"
                }
            }
        }

        Rectangle {
            id: gameSection
            Layout.fillWidth: true
            height: parent.height * 0.1 * 0.7
            color: "#33ff1c1c"
            anchors.top: logo.bottom

            Text {
                anchors.fill: parent
                padding: 10
                text: "Игры"
                font: csButton.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideMiddle
                renderType: Text.NativeRendering
                color: "white"
            }

            layer.enabled: true
            layer.effect: DropShadow {
                radius: 8.0
                samples: 16
                color: "#000000"
            }

        }

        Button {
            id: csButton
            text: "CS:GO"
            anchors.top: gameSection.bottom

            padding: 10

            contentItem: Text {
                      text: parent.text
                      font: parent.font
                      horizontalAlignment: Text.AlignLeft
                      verticalAlignment: Text.AlignVCenter
                      elide: Text.ElideRight
                      renderType: Text.NativeRendering
                      color: "white"
                  }

            background: Rectangle {
                color: "#00000000"
            }

            Layout.fillWidth: true

            onClicked: {
                stack.replace(newsPage)
                drawerLocal.close()
            }
        }

        Button {
            id: dotaButton
            text: "Dota 2"
            padding: 10
            anchors.top: csButton.bottom
            contentItem: Text {
                      text: parent.text
                      font: parent.font
                      horizontalAlignment: Text.AlignLeft
                      verticalAlignment: Text.AlignVCenter
                      elide: Text.ElideRight
                      color: "white"
                  }

            background: Rectangle {
                color: "#00000000"
            }

            Layout.fillWidth: true

            onClicked: {
                stack.replace(matchPage)
                drawerLocal.close()
            }
        }

        Button {
            text: "LoL"
            padding: 10
            anchors.top: dotaButton.bottom
            contentItem: Text {
                      text: parent.text
                      font: parent.font
                      horizontalAlignment: Text.AlignLeft
                      verticalAlignment: Text.AlignVCenter
                      elide: Text.ElideRight
                      color: "white"
                  }

            background: Rectangle {
                color: "#00000000"
            }

            Layout.fillWidth: true

            onClicked: {
                stack.replace(discussPage)
                drawerLocal.close()
            }

        }

        Item { Layout.fillHeight: true }

        Button {
            text: "Настройки"

            padding: 10

            background: Rectangle {
                color: "#00000000"
            }

            contentItem: Text {
                      text: parent.text
                      font: parent.font
                      horizontalAlignment: Text.AlignLeft
                      verticalAlignment: Text.AlignVCenter
                      elide: Text.ElideRight
                      color: "white"
                  }


            Layout.fillWidth: true

            onClicked: {

                drawerLocal.close()
            }

        }

        Item { height: 2 }
    }
}
