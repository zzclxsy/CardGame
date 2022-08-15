import QtQuick 2.0
import QtQml 2.12
import JHFramework 1.0
import "../JHQmlControl"
Item {

    id:item0
    property var shuffleCard:[]
    property int dealCardindex:0
    JHMessageClient{
        domain:"card"
        filter: {
            ["shuffleCard"]
        }

        onHasDomainData: {
            var ret = JSON.parse(data)
            shuffleCard = ret["shuffleCard"]
            console.log(shuffleCard)
        }
    }

    CardManager{
        id:cardManager
        onCardClicked: {
            player.cardClicked(sender)
        }
    }

    Rectangle {
        id: mainRect
        anchors.fill: parent

        JHBottom{
            x: 237
            y: 137
            width: 174
            height: 59
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            imageSorce: "qrc:/image/start_immediately.png"
            onBottomClicked: {
                this.visible = false
                app.JHCardManager.shuffleCards("JHLandlordsRule")
                cardManager.bkCardShow(item0.width/2,item0.height/2)
                time.start()
            }
        }

        Player {
            id: player
            drectoon:"下"
            y: 324
            height: 156
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 85
            anchors.leftMargin: 103
            anchors.bottomMargin: 0
        }

        Player {
            id: player1
            drectoon:"右"
            x: 468
            width: 172
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 118
            anchors.topMargin: 0
            anchors.rightMargin: 0
        }

        Player {
            id: player2
            drectoon:"左"
            width: 166
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 108
            anchors.topMargin: 0
            anchors.leftMargin: 0
        }
    }

    Timer{
        id:time
        interval: 60
        repeat: true
        onTriggered: {
            if ( dealCardindex%3 === 0)//下
            {
                cardManager.move(item0.width/2,item0.height - cardManager.bkCard0.height)
                player.setCard(cardManager.cards[shuffleCard[dealCardindex]])
            }

            else if ( dealCardindex%3 === 1)//右
            {
                cardManager.move(item0.width - cardManager.bkCard0.width, item0.height/2)
                player1.setCard(cardManager.cards[shuffleCard[dealCardindex]])
            }
            else if ( dealCardindex%3 === 2)//左
            {
                cardManager.move(cardManager.bkCard0.width,item0.height/2)
                player2.setCard(cardManager.cards[shuffleCard[dealCardindex]])
            }
            dealCardindex = dealCardindex + 1
            if(dealCardindex === shuffleCard.length)
            {
                time.stop()
                player.dealCardFinish()
                player1.dealCardFinish()
                player2.dealCardFinish()
            }
        }
    }

    function test()
    {
        var id = 0
        for (var i = 0; i < 5 ;i++)
        {
            for (var j = 0; j < 13; j++)
            {
                cardManager.cards[shuffleCard[id]].visible = true
                cardManager.cards[shuffleCard[id]].x = j*45
                cardManager.cards[shuffleCard[id]].y =i*60
                id++
                if (id === 54)
                    break
            }

            if (id === 54)
                break
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.9;height:480;width:640}
}
##^##*/
