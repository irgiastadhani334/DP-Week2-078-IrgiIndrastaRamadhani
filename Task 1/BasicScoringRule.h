#ifndef BASIC_SCORING_RULE_H
#define BASIC_SCORING_RULE_H

#include "IScoringRule.h"

// Score equals the raw input value
class BasicScoringRule : public IScoringRule {
public:
    int compute(const TurnInput& input) override {
        return input.value;
    }
};

#endif
