#ifndef JHCARDIMAGE_H
#define JHCARDIMAGE_H

#include <QQuickImageProvider>
#include <QMap>
class JHCardImage : public QQuickImageProvider
{

public:
    explicit JHCardImage();
    void AddCardImage(QString id, QImage &image);
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)override;
    int CardCount();

private:
    QMap<QString, QImage> m_cardImages;//key :id, value: image

};

#endif // JHCARDIMAGE_H
