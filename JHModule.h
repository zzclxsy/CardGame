#ifndef JHMODULE_H
#define JHMODULE_H
#include "JHObject.h"
class QQmlEngine;
class JHModule:public JHObject
{
public:
    JHModule();
    virtual ~JHModule(){};
    virtual void Initialize(){};
    virtual void Uninitialize(){};
    virtual void RegisterToQml(QQmlEngine *){};
};

#endif // JHMODULE_H
