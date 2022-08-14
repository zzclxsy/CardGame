#ifndef JHMESSAGESERVER_H
#define JHMESSAGESERVER_H
#include <QObject>
#include<QList>
class JHMessageClient;
class JHMessageServer:public QObject
{
    Q_OBJECT
public:
    JHMessageServer();
    ~JHMessageServer();

    void AddClient(JHMessageClient *);
    const QString &GetDomain() const;
    void SetDomain(const QString &newDomain);
    void SendDomainData(QString data);

protected:
    void DomainChange(QString domain);
    void DomainDataChange(QString data);
private:
    QList<JHMessageClient *> m_clients;
    QString m_domain;
    QString m_domainData;
};

#endif // JHMESSAGESERVER_H
