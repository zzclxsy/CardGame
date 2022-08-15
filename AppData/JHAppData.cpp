#include "JHAppData.h"
#include "JHMessageServer.h"
#include "JHMessageClient.h"
#include <QDebug>
#include <QQmlEngine>

JHAppData::JHAppData()
{
    m_cardDomain = "card";
}

void JHAppData::CreateDomain(QString domain)
{
    if (m_messageServers.contains(domain) == false) {
        m_messageServers.insert(domain, new JHMessageServer());
        m_messageServers[domain]->SetDomain(domain);
        return;
    }

    qWarning()<<"JHAppData::CreateDomain:"<<"已存在该domain";
}

void JHAppData::AddClient(JHMessageClient *client, QString domain)
{
    if (m_messageServers.contains(domain) == false){
        CreateDomain(domain);
    }

    m_messageServers.value(domain)->AddClient(client);
}

void JHAppData::SendDomainData(QString domain, QString data)
{
    auto it = m_messageServers.find(domain);
    if (it != m_messageServers.end())
    {
        m_messageServers.value(domain)->SendDomainData(data);
    }
}

void JHAppData::SetCardDomain(const QString &newCardDomain)
{
    if (m_cardDomain == newCardDomain)
        return;
    m_cardDomain = newCardDomain;
    emit cardDomainChanged();
}

const QString &JHAppData::GetCardDomain() const
{
    return m_cardDomain;
}
