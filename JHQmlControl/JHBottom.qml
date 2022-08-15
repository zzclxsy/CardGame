import QtQuick 2.0
import QtGraphicalEffects 1.12
Item {
    property string imageSorce
    property string bottomText
    property string bottomTextColor:"#ffffff"
    signal bottomClicked()

    FontLoader { id: localFont; source: "qrc:/font/FZZY.TTF" }
    Rectangle {
        x: 0
        y: 239
        width: 165
        height: 61
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        Image {
            id:image
            anchors.fill: parent
            source: imageSorce
        }

        ColorOverlay{
            anchors.fill: image
            source: image
            color: "#00F5F5F5"

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    bottomClicked()
                }
                onEntered: {
                    parent.color = "#39F5F5F5"
                }
                onExited: {
                    parent.color = "#00b7aeae"
                }

                Text {
                    color: bottomTextColor
                    text:bottomText
                    anchors.fill: parent
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: localFont.name
                    font.bold: true
                    layer.enabled:true
                    layer.effect: Glow {
                        color: "#000000"
                        radius: 6
                        samples: 13
                        spread: 0.2
                    }
                }
            }
        }

    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5}
}
##^##*/
