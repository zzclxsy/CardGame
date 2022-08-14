import QtQuick 2.0

Item {
    id:item0
    property alias imageSource: image.source
    property var index
    property var sortIndex
    property bool mainPlay:false
    signal cardClicked(var sender)
    visible:false
    Rectangle{
        anchors.fill: parent
        color: "#00000000"
        Image {
            id:image
            anchors.fill: parent
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if (mainPlay)
                    cardClicked(item0)
            }
        }
    }
}
