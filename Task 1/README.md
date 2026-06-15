# Task 1 - Balatro-Like Run Core Loop

## Reflection

### 1. What is the invariant structure in your program?

The invariant structure is the phase order enforced inside RunSession::start().
Every round must follow this exact sequence: generate input, compute base score,
compute reward, update money, run shop, then advance to the next round.
This order must never change because each phase depends on the output of the
phase before it. The score cannot be computed before input exists, the reward
cannot be computed before the score is known, and money cannot be updated before
the reward is calculated. RunSession exists specifically to protect this sequence.

### 2. Which parts are mutable?

The mutable parts are the concrete implementations behind each interface.
IInputGenerator can be swapped to change how input is produced. IScoringRule
can be swapped to change how the base score is calculated. IRewardRule can be
swapped to change how money is earned each round. The shop offer content and
the number of rounds are also mutable. None of these affect the phase order
because RunSession only depends on the interfaces, not the implementations.

### 3. When you replaced the InputGenerator, why didn't RunSession change?

Because RunSession depends on the IInputGenerator interface, not any specific
implementation. It only calls generate() and receives a TurnInput. It does not
care whether the value is fixed or random. The detail of how input is produced
is hidden behind the interface, so a new generator can be swapped in main.cpp
without touching RunSession at all.

### 4. What would happen if scoring logic was placed inside RunSession?

RunSession would be responsible for both controlling the loop and computing the
score. Any change to the scoring formula would require modifying RunSession
directly, risking an accidental break in the phase order. It would also make it
impossible to swap scoring behavior without rewriting the core loop class.
Keeping scoring inside IScoringRule ensures RunSession does one thing only:
enforce the correct phase sequence every round.
