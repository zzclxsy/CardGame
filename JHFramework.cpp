#include "JHFramework.h"
#include "JHModule.h"
#include <QDebug>
#include "QQmlEngine"
#include <QQmlContext>
#include "CardManager/JHCardImage.h"
#include "AppData/JHMessageClient.h"
#include "AppData/JHAppData.h"
#include "CardManager/JHCardManager.h"
#include "CardRule/JHLandlordsRule.h"
#include "Player/JHPlayer.h"

static JHFramework *mp_app = nullptr;

JHFramework::JHFramework()
{
    mp_app = this;
}

void JHFramework::Initialize()
{
    mp_appData = new JHAppData;
    mp_cardManager = new JHCardManager;
    AddModule("JHAppData", mp_appData);
    AddModule("JHCardManager", mp_cardManager);
    AddModule("JHLandlordsRule", new JHLandlordsRule);

    qmlRegisterType<JHPlayer>("JHFramework",1,0,"JHPlayer");
    qmlRegisterType<JHMessageClient>("JHFramework",1,0,"JHMessageClient");
    qmlRegisterUncreatableType<JHAppData>("JHFramework",1,0,"JHAppData","JHAppData Register Fail");
    qmlRegisterUncreatableType<JHCardManager>("JHFramework",1,0,"JHCardManager","JHCardManager Register Fail");

    m_engine->addImageProvider(QLatin1String("JHCardImage"), mp_cardManager->GetImageManager());
}

JHFramework *JHFramework::GetApp()
{
    if (mp_app == nullptr){
        return new JHFramework;
    }
    return mp_app;
}

void JHFramework::AddModule(QString moduleName, JHModule *module)
{
    QMutexLocker lock(&m_Mutex);
    if(m_modules.contains(moduleName)){
        qWarning()<<"JHFramework::AddModule:"<<"该模块已经存在，删除后再添加";
        return;
    }
    module->Initialize();
    dynamic_cast<JHObject *>(module)->SetFramework(this);
    m_modules.insert(moduleName, module);
}

void JHFramework::RemoveModule(QString moduleName)
{
    QMutexLocker lock(&m_Mutex);
    if (m_modules.contains(moduleName)) {
        m_modules.value(moduleName)->Uninitialize();
        m_modules.remove(moduleName);
        return;
    }

    qWarning()<<"JHFramework::RemoveModule:"<<"没有找到该模块";
}

void JHFramework::SetQmlEngine(QQmlEngine *engine)
{
    m_engine = engine;
}

JHAppData *JHFramework::GetAppData() const
{
    return mp_appData;
}

void JHFramework::SetAppData(JHAppData *newAppData)
{
    if (mp_appData == newAppData)
        return;
    mp_appData = newAppData;
}

JHCardManager *JHFramework::GetCardManager() const
{
    return mp_cardManager;
}

void JHFramework::SetCardManager(JHCardManager *newJHCardManager)
{
    if (mp_cardManager == newJHCardManager)
        return;
    mp_cardManager = newJHCardManager;
}
