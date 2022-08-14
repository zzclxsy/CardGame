#ifndef JHFRAMEWORK_H
#define JHFRAMEWORK_H
#include <QMap>
#include <QObject>
#include <QMutex>
#include "AppData/JHAppData.h"
#include "CardManager/JHCardManager.h"
#include "CardRule/JHLandlordsRule.h"
class JHModule;
class JHFramework:public QObject
{
    Q_OBJECT

public:
    JHFramework();

    static JHFramework *GetApp();

    void AddModule(QString moduleName,JHModule*);
    void RemoveModule(QString moduleName);
    void SetQmlEngine(QQmlEngine *);
    template<typename  T>
    T* GetModule(QString moduleName){
        QMutexLocker lock(&m_Mutex);
        if (m_modules.contains(moduleName))
            return static_cast<T *>(m_modules.value(moduleName));
        return nullptr;
    }

private:
    QMap<QString, JHModule*> m_modules;
    QMutex m_Mutex;
    JHAppData m_appData;
    QQmlEngine *m_engine;
};

#endif // JHFRAMEWORK_H
