#ifndef RANDOM_INPUT_GENERATOR_H
#define RANDOM_INPUT_GENERATOR_H

#include "IInputGenerator.h"
#include <cstdlib>

// Modification 1: replaces FixedInputGenerator.
// Generates a random value between 1 and 10.
// RunSession was NOT changed to support this.
class RandomInputGenerator : public IInputGenerator {
public:
    TurnInput generate() override {
        return TurnInput{ (rand() % 10) + 1 };
    }
};

#endif
