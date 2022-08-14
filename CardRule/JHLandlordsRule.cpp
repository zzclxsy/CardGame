#include "JHLandlordsRule.h"

JHLandlordsRule::JHLandlordsRule()
{

}

void JHLandlordsRule::ShuffleCardRule(QList<int> &result)
{
    for (int i = result.count()-1; i >= 0; --i)
    {
        srand((unsigned)time(NULL));
        result.swap(rand()%(i+1),i);
    }
}

int JHLandlordsRule::DispatchCardRule()
{
    return 1;
}
