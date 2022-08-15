import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import JHFramework 1.0
import "../JHQmlControl"
Window {
    id: window
    width: 1200
    height: 800
    visible: true
    title: qsTr("Hello World")


    LandlordUI{
        anchors.fill: parent
    }
}
