#include "JHMessageClient.h"
#include "JHFramework.h"
#include "JHAppData.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonParseError>
#include "Utility.h"
JHMessageClient::JHMessageClient()
{

}


const QString &JHMessageClient::GetDomain() const
{
    return m_domain;
}

void JHMessageClient::SetDomain(const QString &newDomain)
{
    qDebug()<<"JHMessageClient::SetDomai:"<<newDomain;
    if (m_domain == newDomain)
        return;
    m_domain = newDomain;
    JHFramework::GetApp()->GetModule<JHAppData>("JHAppData")->AddClient(this, m_domain);
    emit domainChanged(m_domain);
}

void JHMessageClient::sendDomainData(QString data)
{
    JHFramework::GetApp()->GetModule<JHAppData>("JHAppData")->SendDomainData(m_domain, data);
}

const QString &JHMessageClient::GetDomainData() const
{
    return m_domainData;
}

void JHMessageClient::SetDomainData(const QString &newDomainData)
{
    if (m_domainData == newDomainData)
        return;
    m_domainData = newDomainData;
    emit domainDataChanged(m_domainData);
}

const QStringList &JHMessageClient::GetFilter() const
{
    return m_filter;
}

void JHMessageClient::SetFilter(const QStringList &newFilter)
{
    if (m_filter == newFilter)
        return;

    m_filter = newFilter;
}

void JHMessageClient::JudgeFilterAndSend(QString data)
{
    QJsonObject newRoot;

    QJsonParseError jossError;//用于判断是否出错
    QJsonDocument  doc = QJsonDocument::fromJson(data.toUtf8(), &jossError);//字符串格式化为JSON

    do
    {
        if (jossError.error != QJsonParseError::NoError){
            qCritical()<<"JHMessageClient::JudgeFilterAndSend:jossError.error:"<<jossError.error;
            break;
        }
        QJsonObject oldRoot = doc.object();
        foreach(QString filter, m_filter){
            if (oldRoot.contains(filter)){
                newRoot[filter] = oldRoot.value(filter);
            }
        }

        if (newRoot.isEmpty() == false)
            emit hasDomainData(Utility::JsonToString(newRoot));

    }while(0);
}
