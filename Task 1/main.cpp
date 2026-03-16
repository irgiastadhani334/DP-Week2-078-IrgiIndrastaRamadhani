#include "RunSession.h"
#include "FixedInputGenerator.h"
#include "BasicScoringRule.h"
#include "BasicRewardRule.h"

int main() {
    FixedInputGenerator inputGen;
    BasicScoringRule    scoringRule;
    BasicRewardRule     rewardRule;

    RunSession session(&inputGen, &scoringRule, &rewardRule, 3);
    session.start();

    return 0;
}
