#ifndef RUN_SESSION_H
#define RUN_SESSION_H

#include <iostream>
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

// RunSession owns the invariant phase order.
// It does NOT contain scoring, reward, or input logic.
class RunSession {
private:
    IInputGenerator* inputGen;
    IScoringRule*    scoringRule;
    IRewardRule*     rewardRule;
    ShopSystem       shop;
    int              money;
    int              totalRounds;

public:
    RunSession(IInputGenerator* gen, IScoringRule* scoring, IRewardRule* reward, int rounds = 3)
        : inputGen(gen), scoringRule(scoring), rewardRule(reward), money(0), totalRounds(rounds) {}

    void start() {
        std::cout << "=== RUN START ===\n\n";

        for (int round = 1; round <= totalRounds; round++) {
            std::cout << "Round " << round << "\n";

            // Phase 1: Generate input
            TurnInput input = inputGen->generate();
            std::cout << "[PLAY]   input generated: " << input.value << "\n";

            // Phase 2: Compute base score
            int baseScore = scoringRule->compute(input);
            std::cout << "[SCORE]  base score: " << baseScore << "\n";

            // Phase 3: Compute reward
            int reward = rewardRule->compute(baseScore, round);
            std::cout << "[REWARD] gain: " << reward;

            // Phase 4: Update money
            money += reward;
            std::cout << " | money: " << money << "\n";

            // Phase 5: Shop phase
            shop.offer(money);

            // Phase 6: Advance round
            std::cout << "\n";
        }

        std::cout << "=== RUN END ===\n";
        std::cout << "Final money: " << money << "\n";
    }
};

#endif
