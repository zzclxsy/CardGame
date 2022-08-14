#include "JHCardImage.h"
#include <QDebug>
JHCardImage::JHCardImage() : QQuickImageProvider(QQuickImageProvider::Image)
{

}

void JHCardImage::AddCardImage(QString id, QImage &image)
{
    auto it = m_cardImages.find(id);
    if (it == m_cardImages.end())
    {
        m_cardImages.insert(id, image);
    }
}

QImage JHCardImage::requestImage(const QString &id, QSize *, const QSize &)
{
    QString key = id;
    auto it = m_cardImages.find(key.remove("id="));
    if (it != m_cardImages.end())
    {
        return it.value();
    }
    return QImage();
}

QPixmap JHCardImage::requestPixmap(const QString &id, QSize *, const QSize &)
{
    QString key = id;
    auto it = m_cardImages.find(key.remove("id="));
    if (it != m_cardImages.end())
        return QPixmap::fromImage(it.value());

    return QPixmap();
}

int JHCardImage::CardCount()
{
    return m_cardImages.size();
}
