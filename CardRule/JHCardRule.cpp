#include "JHCardRule.h"

JHCardRule::JHCardRule()
{

}

JHCardRule::~JHCardRule()
{

}

void JHCardRule::ShuffleCardRule(QList<int> &result)
{
    for (int i = result.count()-1; i >= 0; --i)
    {
        srand((unsigned)time(NULL));
        result.swap(rand()%(i+1),i);
    }
}
