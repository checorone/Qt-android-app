import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0


ApplicationWindow {

      id: wd
      title: qsTr("Hello World")
      width: 320
      height: 500
      visible: true

      signal reSet(int index)
      signal getNews()

      header: Bar {
          id: bar
          width: parent.width

      }

      Stack {
          id: stack
          anchors.fill: parent
      }


      DrawerPanel {
          id: drawer
      }

      Component {
          id: newsPage

          Page {
              id: news

              SwipeView {
                  id: swipeView
                  anchors.fill: parent
                  currentIndex: tabBar.currentIndex
                  clip: true


                  Page {
                      NewsPage {
                      }
                  }

                  Page {
                      MatchPage {
                      }
                  }

                  Page {
                      DiscussPage {
                      }
                  }
              }

              header: TabBar {
                  id: tabBar

                  currentIndex: swipeView.currentIndex
                  TabButton {
                      text: qsTr("Новости")
                  }
                  TabButton {
                      text: qsTr("Матчи")
                  }
                  TabButton {
                      text: qsTr("Обсуждения")
                  }
              }
          }
      }

      Component {
          id: matchPage
          MatchPage {
          }
      }

      Component {
          id: discussPage
          DiscussPage {
          }
      }
}



