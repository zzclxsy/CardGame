#include "JHFramework.h"
#include "JHModule.h"
#include <QDebug>
#include "QQmlEngine"
static JHFramework *mp_app = nullptr;

JHFramework::JHFramework()
{
    mp_app = this;
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
    module->RegisterToQml(m_engine);
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
