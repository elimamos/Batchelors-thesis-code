import QtQuick 2.4
import QtQuick.Controls 1.5

Item {
    width: 400
    height: 400

    Grid {
        id: grid1
        x: 0
        y: 0
        width: 400
        height: 400
    }

    RadioButton {
        id: radioButton1
        x: 143
        y: 91
        text: qsTr("Radio Button")
    }
}
