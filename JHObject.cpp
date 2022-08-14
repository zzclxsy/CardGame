#include "JHObject.h"

JHObject::JHObject()
{

}

void JHObject::SetFramework(JHFramework *framework)
{
    m_framework = framework;
}

JHFramework *JHObject::GetFramework()
{
    return m_framework;
}
