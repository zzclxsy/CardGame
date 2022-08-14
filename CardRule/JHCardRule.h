#ifndef JHCARDRULE_H
#define JHCARDRULE_H
#include <QList>
class JHCardRule
{
public:
    JHCardRule();
    virtual ~JHCardRule();

    virtual void ShuffleCardRule(QList<int> &cards) = 0;
    virtual int DispatchCardRule() = 0;
};

#endif // JHCARDRULE_H
