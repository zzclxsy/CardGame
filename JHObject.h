#ifndef JHOBJECT_H
#define JHOBJECT_H
#include <QObject>
class JHFramework;
class JHObject:public QObject
{
public:
    JHObject();

    void SetFramework(JHFramework *framework);
    JHFramework *GetFramework();
private:
    JHFramework *m_framework;
};

#endif // JHOBJECT_H
