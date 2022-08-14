#include "Utility.h"
#include <QJsonDocument>

QString Utility::JsonToString(QJsonObject &json)
{
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Indented);
    return QString (byteArray);
}
