import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12
import JHFramework 1.0

Window {
    id: window
    width: 1500
    height: 1000
    visible: true
    title: qsTr("Hello World")

    LandlordUI{
        anchors.fill: parent
    }
}
