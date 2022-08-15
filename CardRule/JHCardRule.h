#ifndef JHCARDRULE_H
#define JHCARDRULE_H
#include <QList>
class JHCardRule
{
public:
    JHCardRule();
    virtual ~JHCardRule();
    //默认随机洗牌
    virtual void ShuffleCardRule(QList<int> &cards);
};

#endif // JHCARDRULE_H
