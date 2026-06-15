#ifndef BONUS_REWARD_RULE_H
#define BONUS_REWARD_RULE_H

#include "IRewardRule.h"

// Modification 2: replaces BasicRewardRule.
// Reward is no longer equal to base score.
// Odd rounds:  reward = baseScore + 2
// Even rounds: reward = baseScore * 2
// RunSession was NOT changed to support this.
class BonusRewardRule : public IRewardRule {
public:
    int compute(int baseScore, int round) override {
        if (round % 2 == 0) {
            return baseScore * 2;
        }
        else {
            return baseScore + 2;
        }
    }
};

#endif
