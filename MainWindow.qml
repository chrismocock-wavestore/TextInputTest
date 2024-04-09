import QtQuick
import QtQuick.Controls
import TextInputTest

Item {
    Rectangle {
        id: frame
        width: 200
        height: 25
        border.color: 'gray'
        border.width: 1

        TextInput {
            id: textInput
            anchors.fill: parent
            anchors.margins: 4
        }
    }
}
