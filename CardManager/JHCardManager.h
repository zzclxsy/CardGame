#ifndef JHCARDMANAGER_H
#define JHCARDMANAGER_H

#include <QMap>
#include <JHModule.h>
#include <JHObject.h>

class JHCardImage;
class QQmlEngine;
class JHCard;
class JHCardRule;
class JHCardManager:
        public JHModule
{
    Q_OBJECT
public:
    Q_INVOKABLE void shuffleCards();

public:
    explicit JHCardManager();

    void Initialize() override;
    void RegisterToQml(QQmlEngine *engine)override;
    JHCard *GetCard(int index);

private:
    JHCardImage *mp_imageManager;
    QMap<int , JHCard*> m_cards;
    JHCardRule *mp_cardRule;
signals:
    void initializationFinish();
};

#endif // JHCARDMANAGER_H
