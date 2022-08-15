#ifndef JHFRAMEWORK_H
#define JHFRAMEWORK_H
#include <QMap>
#include <QObject>
#include <QMutex>
class JHModule;
class JHAppData;
class JHCardManager;
class QQmlEngine;
class JHFramework:public QObject
{
    Q_OBJECT
    Q_PROPERTY(JHAppData* JHAppData READ GetAppData WRITE SetAppData)
    Q_PROPERTY(JHCardManager* JHCardManager READ GetCardManager WRITE SetCardManager)

public:
    JHFramework();
    void Initialize();
    static JHFramework *GetApp();

    void AddModule(QString moduleName,JHModule*);
    void RemoveModule(QString moduleName);
    void SetQmlEngine(QQmlEngine *);
    template<typename  T>
    T* GetModule(QString moduleName){
        QMutexLocker lock(&m_Mutex);
        if (m_modules.contains(moduleName))
            return dynamic_cast<T *>(m_modules.value(moduleName));
        return nullptr;
    }

    JHAppData *GetAppData() const;
    void SetAppData(JHAppData *newAppData);

    JHCardManager *GetCardManager() const;
    void SetCardManager(JHCardManager *newJHCardManager);

private:
    QMap<QString, JHModule*> m_modules;
    QMutex m_Mutex;
    JHAppData *mp_appData;
    JHCardManager *mp_cardManager;
    QQmlEngine *m_engine;
};

#endif // JHFRAMEWORK_H
