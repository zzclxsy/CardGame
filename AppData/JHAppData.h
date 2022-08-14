#ifndef JHAPPDATA_H
#define JHAPPDATA_H

#include <JHModule.h>
#include <JHObject.h>
#include <QMap>
class JHMessageClient;
class JHMessageServer;
class JHAppData : public JHModule
{
    Q_OBJECT
    Q_PROPERTY(QString CardDomain READ GetCardDomain WRITE SetCardDomain NOTIFY cardDomainChanged)
public:
    JHAppData();
    void RegisterToQml(QQmlEngine *);
    void CreateDomain(QString domain);
    void AddClient(JHMessageClient *client, QString domain);
    void SendDomainData(QString domain,QString data);

    void SetCardDomain(const QString &newCardDomain);
    const QString &GetCardDomain() const;

signals:
    void cardDomainChanged();

private:
    QMap<QString, JHMessageServer*> m_messageServers;//key :domain
    QString m_cardDomain;
};

#endif // JHAPPDATA_H
