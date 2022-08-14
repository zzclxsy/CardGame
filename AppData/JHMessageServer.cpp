#include "JHMessageServer.h"
#include "JHMessageClient.h"
#include <QDebug>
JHMessageServer::JHMessageServer()
{

}

JHMessageServer::~JHMessageServer()
{
}

void JHMessageServer::AddClient(JHMessageClient *client)
{
    connect(client, &JHMessageClient::domainChanged, this, &JHMessageServer::DomainChange);
    connect(client, &JHMessageClient::domainDataChanged, this, &JHMessageServer::DomainDataChange);

    if (m_clients.contains(client) == false)
        m_clients.append(client);
}

const QString &JHMessageServer::GetDomain() const
{
    return m_domain;
}

void JHMessageServer::SetDomain(const QString &newDomain)
{
    if (m_domain == newDomain)
        return;
    m_domain = newDomain;
}

void JHMessageServer::SendDomainData(QString data)
{
    m_domainData = data;
    foreach(JHMessageClient *client, m_clients)
    {
        client->JudgeFilterAndSend(data);
    }
}

void JHMessageServer::DomainChange(QString domain)
{
    if (domain != m_domain)
    {
        qDebug()<<"JHMessageServer::DomainChange"<<domain<<m_domain;
        JHMessageClient *client = static_cast<JHMessageClient *>(sender());
        disconnect(client, &JHMessageClient::domainChanged, this, &JHMessageServer::DomainChange);
        m_clients.removeOne(client);
    }
}

void JHMessageServer::DomainDataChange(QString data)
{
    if (m_domainData != data){
        SendDomainData(data);
    }
}
