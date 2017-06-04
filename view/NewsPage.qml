import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Page {  
        id: newsBox

        objectName: "news"


        width: wd.width
        height: wd.height - bar.height
        z:0

        anchors.top: wd.bottom

        background: Rectangle {
            anchors.fill: parent



//            LinearGradient {
//                anchors.fill: parent
//                start: Qt.point(0, 0)
//                end: Qt.point(0, 300)
//                gradient: Gradient {
//                    GradientStop { position: 0.25; color: "white" }
//                    GradientStop { position: 1.0; color: "#42c1f4" }
//                }
//            }

            Image {
                anchors.fill: parent
                source: "../resources/back.png"
            }



        }

        ListView {
            id: view

            model: VM.news

            spacing: 25

            anchors.margins: 15
            anchors.fill: parent


            delegate: Item {
                id: listDelegate

                width: view.width
                height: label.height + shortText.height

//                MultiPointTouchArea {
//                    anchors.fill: parent
//                    touchPoints: [ TouchPoint { id: point1 } ]
//                    onPressed: stack.push(content)
//                }

                MouseArea {
                   anchors.fill: parent
                   onClicked: stack.push(fulltxt)
                }

                Component {
                    id: fulltxt

                    Flickable {
                        contentHeight: content.height + label.height
                        contentWidth: content.width

                        Rectangle {
                            height: contentHeight
                            width:  contentWidth
                            anchors.top: labelBox.bottom
                            Image {
                                source: "../resources/back.png"
                            }
                        }

                        Rectangle {
                            id: labelBox
                            height: label.height * 0.8
                            width: label.width
                            anchors.top: label.top
                            color: "#77ff1c1c"

                            Text {
                                id: label
                                anchors.top: bar.bottom
                                font: bar.font
                                padding: 20
                                verticalAlignment: Text.AlignVCenter
                                horizontalAlignment: Text.AlignHCenter
                                width: wd.width
                                text: model.label
                                wrapMode: Text.WordWrap
                                color: "white"
                            }
                        }



                        Text {
                            id: content
                            anchors.top: labelBox.bottom
                            padding: 20
                            font: bar.font
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignLeft
                            width: wd.width
                            text: model.shortText
                            wrapMode: Text.WordWrap
                            color: "black"
                        }
                    }

                }


                ColumnLayout {
                    spacing: 0

                    anchors.fill: parent

                    layer.enabled: true
                    layer.effect: DropShadow {
                        radius: 16.0
                        samples: 32
                        color: "#80000000"
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        width: parent.width
                        height: label.height

                        color: "#333333"
                        Text {
                            id: label
                            padding: 10
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignLeft
                            width: parent.width
                            text: model.label
                            smooth: true
                            color: "white"
                            wrapMode: Text.WordWrap
                            elide: Text.ElideRight
                        }


                    }

                    Rectangle {
                        Layout.fillWidth: true
                        width: parent.width
                        height: shortText.height

                        color: "#ffffff"

                        Text {
                            id: shortText
                            padding: 10
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignLeft
                            width: parent.width
                            text: model.fullText
                            color: "black"
                            wrapMode: Text.WordWrap
                            elide: Text.ElideRight
                        }


                    }
                }

            }

            footer: Button {

                text: "Загрузить еще"
                width: parent.width

                onPressed: wd.getNews()
            }

        }
}
