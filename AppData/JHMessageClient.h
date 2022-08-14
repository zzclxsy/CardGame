#ifndef JHMESSAGECLIENT_H
#define JHMESSAGECLIENT_H
#include <QString>
#include <QObject>
class JHMessageClient:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString domain READ GetDomain WRITE SetDomain)
    Q_PROPERTY(QString domainData READ GetDomainData WRITE SetDomainData NOTIFY domainDataChanged)
    Q_PROPERTY(QStringList filter READ GetFilter WRITE SetFilter)
public:
    Q_INVOKABLE void sendDomainData(QString data);

public:
    JHMessageClient();
    const QString &GetDomain() const;
    void SetDomain(const QString &newDomain);

    const QString &GetDomainData() const;
    void SetDomainData(const QString &newDomainData);

    const QStringList &GetFilter() const;
    void SetFilter(const QStringList &newFilter);

    void JudgeFilterAndSend(QString data);

signals:
    void domainChanged(QString domain);
    void domainDataChanged(QString data);

    void hasDomainData(QString data);


private:
    QString m_domain;
    QString m_domainData;
    QStringList m_filter;
};

#endif // JHMESSAGECLIENT_H
