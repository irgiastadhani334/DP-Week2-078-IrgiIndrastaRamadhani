#ifndef IINPUT_GENERATOR_H
#define IINPUT_GENERATOR_H

struct TurnInput {
    int value;
};

class IInputGenerator {
public:
    virtual TurnInput generate() = 0;
    virtual ~IInputGenerator() {}
};

#endif
