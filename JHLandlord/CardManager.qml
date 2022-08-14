import QtQuick 2.0
import QtQml 2.12
Item {
    property var bkCard0
    property var bkCard1
    property var cards:[]

    property int cardWidth: 90
    property int cardheight: 130
    property int restX
    property int restY
    signal cardClicked(var sender)
    function bkCardShow(x,y)
    {
        bkCard0.beginItemX = x
        bkCard0.beginItemY = y
        bkCard1.beginItemX = x
        bkCard1.beginItemY = y

        bkCard0.bkCardShow()
        bkCard1.bkCardShow()
    }

    function move(x,y)
    {
        bkCard1.moveItemX = x - cardWidth/2
        bkCard1.moveItemY = y - cardheight/2
        bkCard1.animationStart()
    }

    function cardClickedSlot(sender)
    {
        cardClicked(sender)
    }

    Component.onCompleted: {
        var sortindex0 = 0
        var sortindex1 = 0
        var sort = 0
        for (var i = 0; i < 55 ;i++)
        {
            var str = "image://JHCardImage?id=" + i;
            var component;
            if (i === 54)
                component = Qt.createComponent("BKCard.qml")
            else
                component = Qt.createComponent("Card.qml")


            if (Component.Ready === component.status) {

                if (i % 13 === 0 && i !== 0)
                {
                    sortindex0++;
                    sortindex1 = 0
                }
                if (i === 52 || i === 53)
                    sort = i
                else
                    sort= sortindex0 + sortindex1

                var object = component.createObject(parent,{"width":cardWidth,"height":cardheight,"imageSource":str,"index":i,"sortIndex":sort})
                sortindex1 = sortindex1 + 4
                if (i === 54)
                {
                    bkCard0 = object
                    var object1 = component.createObject(parent,{"width":cardWidth,"height":cardheight,"imageSource":str})
                    bkCard1 = object1
                }
                else{
                    cards.push(object)
                    object.cardClicked.connect(cardClickedSlot)
                }
            }
        }
    }
}
