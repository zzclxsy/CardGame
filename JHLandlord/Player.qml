import QtQuick 2.0
import JHFramework 1.0
Item {
    id:item0
    property var handCards: []
    property string drectoon
    property string playName
    JHPlayer{
        id:player
        playerName: playName
    }

    function cardClicked(sender)
    {
        if (sender.y ===  mainRect.y+10)
            sender.y = sender.y - 20
        else
            sender.y = sender.y + 20
    }

    function resetCard()
    {
        handCards.length  = 0
    }

    function setCard(card)
    {
        if (drectoon === "下")
            bottom(card)
        if (drectoon === "右"||drectoon === "左")
            right(card)
    }


    function bottom(card)
    {
        card.mainPlay = true
        card.parent = mainRect
        card.visible = true
        card.y = mainRect.y+10
        card.x =300+ handCards.length * 30
        handCards.push(card)
    }

    function right(card)
    {
        card.mainPlay = false
        card.parent = mainRect
        card.rotation = 90
        card.visible = true
        card.x =mainRect.x + 30
        card.y =handCards.length * 30
        handCards.push(card)
    }

    function dealCardFinish()
    {
        //重新按照大小排序
        for (var i = 0; i < handCards.length ; i++)
        {
            handCards[i].parent = null
        }
        for (var i = 0; i < handCards.length ; i++)
        {
            for (var j = handCards.length - 1; j > i;j--)
            {
                if (handCards[j].sortIndex < handCards[j -1].sortIndex)
                {

                    var tmp = handCards[j]
                    handCards[j] = handCards[j -1]
                    handCards[j -1] = tmp
                }
            }
        }

        for (var i = 0; i < handCards.length ; i++)
        {
            handCards[i].parent = mainRect
            if (drectoon == "下")
            {
                handCards[i].y = mainRect.y+10
                handCards[i].x =300+ i * 30
            }else if (drectoon === "右"||drectoon === "左")
            {
                handCards[i].rotation = 90
                handCards[i].x =mainRect.x + 30
                handCards[i].y =i * 30
            }
        }
    }

    Rectangle{
        id:mainRect
        anchors.fill: parent
    }
}
