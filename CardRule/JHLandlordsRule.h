#ifndef JHLANDLORDSRULE_H
#define JHLANDLORDSRULE_H

#include "JHCardRule.h"
#include "JHModule.h"
class JHLandlordsRule : public JHCardRule,public JHModule
{
public:
    JHLandlordsRule();
    void ShuffleCardRule(QList<int> &result) override;
    int DispatchCardRule() override;
};

#endif // JHLANDLORDSRULE_H
