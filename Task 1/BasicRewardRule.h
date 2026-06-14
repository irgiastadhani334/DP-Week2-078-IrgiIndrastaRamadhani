#ifndef BASIC_REWARD_RULE_H
#define BASIC_REWARD_RULE_H

#include "IRewardRule.h"

// Original reward rule: reward equals base score
class BasicRewardRule : public IRewardRule {
public:
    int compute(int baseScore, int round) override {
        return baseScore;
    }
};

#endif
