#ifndef JHPLAYER_H
#define JHPLAYER_H
#include "JHModule.h"
#include "JHFramework.h"
#include "CardManager/JHCard.h"
#include <QList>
class JHPlayer:public JHModule
{
    Q_OBJECT
    Q_PROPERTY(QString playerName READ GetPlayerName WRITE SetPlayerName)

public:
    Q_INVOKABLE void resetGame();
    Q_INVOKABLE void receiveCard(int index);
public:
    JHPlayer();
    const QString &GetPlayerName() const;
    void SetPlayerName(const QString &newPlayerName);

private:
     QString m_playerName;
     QList<JHCard *>m_handCards;
};

#endif // JHPLAYER_H
