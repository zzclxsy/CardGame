import QtQuick 2.0
Item {
    id:item0
    property alias imageSource: image.source
    property int beginItemX:0
    property int beginItemY:0
    property int moveItemX:0
    property int moveItemY:0

    visible:false
    function bkCardShow()
    {
        x = beginItemX - width/2
        y = beginItemY - height/2
        visible = true
    }

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
          // loops: Animation.Infinite

           NumberAnimation { target: item0; property: "y"; to: moveItemY; easing.type: Easing.InOutQuad; duration: {if(moveItemY === y)return 0;return 50;}}
           NumberAnimation { target: item0; property: "x"; to: moveItemX; easing.type: Easing.InOutQuad; duration: {if(moveItemX === x)return 0;return 50;}}
           NumberAnimation { target: item0; property: "y"; to: beginItemY - height/2 ; easing.type: Easing.InOutQuad; duration: {if((beginItemY - height/2) === y)return 0;return 50;} }
           NumberAnimation { target: item0; property: "x"; to: beginItemX - width/2; easing.type: Easing.InOutQuad; duration: {if((beginItemX - width/2) === x)return 0;return 50;}}
    }

}
