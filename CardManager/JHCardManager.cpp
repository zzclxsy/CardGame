#include "JHCardManager.h"
#include <QQmlEngine>
#include "JHCardImage.h"
#include <QQmlContext>
#include <QDebug>
#include "JHCard.h"
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include "../CardRule/JHCardRule.h"
#include "../AppData/JHAppData.h"
#include <QJsonDocument>
#include "JHFramework.h"
#include "Player/JHPlayer.h"
JHCardManager::JHCardManager()
{
    mp_imageManager = new JHCardImage;
}

JHCardImage *JHCardManager::GetImageManager()
{
    return mp_imageManager;
}

JHCard *JHCardManager::GetCard(int index)
{
    return m_cards.value(index);
}


void JHCardManager::Initialize()
{
    QImage image;
    image.load(":/image/poker.png");

    int imageWidth = image.size().width()/13;
    int imageHeight = image.size().height()/5;
    int id = mp_imageManager->CardCount();

    for (int i = 0; i < 5 ;i++)
    {
        for (int j = 0; j < 13; j++)
        {
            JHCard *card = new JHCard((JHCard::E_CardSuit)i,(JHCard::E_CardNumber)j);
            m_cards.insert(id, card);
            QImage tmp = image.copy(j*imageWidth, i*imageHeight,imageWidth,imageHeight);
            mp_imageManager->AddCardImage(QString::number(id), tmp);
            id++;
        }
        if (id == 52)
            break;
    }
    //添加大小王和背面图片
    id = mp_imageManager->CardCount();
    JHCard *card = new JHCard(JHCard::E_CardSuit::Card_Joker,JHCard::E_CardNumber::Card_SmallJoker);
    m_cards.insert(id, card);
    QImage tmp = image.copy(0*imageWidth, 4*imageHeight,imageWidth,imageHeight);
    mp_imageManager->AddCardImage(QString::number(id), tmp);

    id++;
    card = new JHCard(JHCard::E_CardSuit::Card_Joker,JHCard::E_CardNumber::Card_BigJoker);
    m_cards.insert(id, card);
    tmp = image.copy(1*imageWidth, 4*imageHeight,imageWidth,imageHeight);
    mp_imageManager->AddCardImage(QString::number(id), tmp);

    id++;
    tmp = image.copy(2*imageWidth, 4*imageHeight,imageWidth,imageHeight);
    mp_imageManager->AddCardImage(QString::number(id), tmp);
}



void JHCardManager::shuffleCards(QString ruleType)
{
    qDebug()<<"JHCardManager::shuffleCard";
    QJsonObject root;
    QJsonArray array;

    QList<int> result = m_cards.keys();
    mp_cardRule = GetFramework()->GetModule<JHCardRule>(ruleType);
    mp_cardRule->ShuffleCardRule(result);
    for (int i : qAsConst(result)){
        array.append(i);
    }
    root["shuffleCard"] = array;
    QJsonDocument document(root);
    QString data = document.toJson(QJsonDocument::Compact);

    JHAppData *appData =JHFramework::GetApp()->GetModule<JHAppData>("JHAppData");
    appData->SendDomainData(appData->GetCardDomain(),data);
}

