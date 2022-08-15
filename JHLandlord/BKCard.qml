import QtQuick 2.0
Item {
    id:item0
    property alias imageSource: image.source
    property int moveItemX:0
    property int moveItemY:0

    visible:false

    function animationStart()
    {
        animation.start()
    }

    Rectangle{
        anchors.fill: parent
        Image {
            id:image
            anchors.fill: parent
        }
    }
    SequentialAnimation {
           id:animation
           running: false

           NumberAnimation { target: item0; property: "y"; to: moveItemY; easing.type: Easing.InOutQuad; duration: {if(moveItemY === 0)return 0;return 50;}}
           NumberAnimation { target: item0; property: "x"; to: moveItemX; easing.type: Easing.InOutQuad; duration: {if(moveItemX === 0)return 0;return 50;}}
           NumberAnimation { target: item0; property: "y"; to: 0 ; easing.type: Easing.InOutQuad; duration:0}
           NumberAnimation { target: item0; property: "x"; to: 0; easing.type: Easing.InOutQuad; duration:0}
    }
}
