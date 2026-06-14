#ifndef FIXED_INPUT_GENERATOR_H
#define FIXED_INPUT_GENERATOR_H

#include "IInputGenerator.h"

// Original input generator: always returns a fixed value of 5
class FixedInputGenerator : public IInputGenerator {
public:
    TurnInput generate() override {
        return TurnInput{ 5 };
    }
};

#endif
