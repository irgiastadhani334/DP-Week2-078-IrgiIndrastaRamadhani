#ifndef ISCORING_RULE_H
#define ISCORING_RULE_H

#include "IInputGenerator.h"

class IScoringRule {
public:
    virtual int compute(const TurnInput& input) = 0;
    virtual ~IScoringRule() {}
};

#endif
