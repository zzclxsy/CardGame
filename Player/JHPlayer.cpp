#include "JHPlayer.h"
#include "JHFramework.h"
#include "CardManager/JHCardManager.h"
void JHPlayer::resetGame()
{

}

void JHPlayer::receiveCard(int index)
{
    JHCard *card = GetFramework()->GetModule<JHCardManager>("JHCardManager")->GetCard(index);
    m_handCards.append(card);
}

JHPlayer::JHPlayer()
{
    m_handCards.clear();
}


const QString &JHPlayer::GetPlayerName() const
{
    return m_playerName;
}

void JHPlayer::SetPlayerName(const QString &newPlayerName)
{
    if (m_playerName == newPlayerName)
        return;
    m_playerName = newPlayerName;

    JHFramework::GetApp()->AddModule(m_playerName,this);
}
