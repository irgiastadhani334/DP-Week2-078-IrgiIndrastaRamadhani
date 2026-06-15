# Task 2 - Develop Your Own Core Loop

## Game Concept: Card-Run Game

My game is a card-run game inspired by Balatro. Each round the player is dealt
a hand of cards, scores points from it, and must meet a rising score threshold
to survive. The run continues indefinitely until the player fails to meet the
required score or chooses to quit from the shop.

---

## Step 1 - Core Loop

1. Player is dealt a hand of cards
2. System computes score from the hand
3. Score is compared against the required threshold
4. If score is too low, the run ends
5. Player enters the shop phase
6. Required score increases for the next round
7. Repeat

---

## Step 2 - Invariant Identification

The following order must never change:

1. Deal hand
2. Compute score
3. Check score against requirement
4. Shop phase
5. Advance round

Required components that must always exist:

1. A RunSession controlling the loop and phase order
2. A HandGenerator producing card input each round
3. A ScoringSystem computing and validating the score
4. A ShopSystem presenting options between rounds
5. A rising score threshold tracked across rounds

---

## Step 3 - Mutable Elements

1. Score formula - currently sums all card values, could change to reward pairs or triples
2. Required score scaling - currently multiplies by 1.5, could use flat addition instead
3. Modifier effects - shop can offer different modifiers without changing the phase order
4. Hand size - currently 5 cards, could be adjusted without affecting loop structure
5. Shop item variety - what is offered can change freely each round

---

## Step 4 - C++ Core Loop Skeleton

File structure:

RunSession.h / RunSession.cpp
HandGenerator.h / HandGenerator.cpp
ScoringSystem.h / ScoringSystem.cpp
ShopSystem.h / ShopSystem.cpp
main.cpp

### Core loop inside RunSession:

void RunSession::StartRun() {
    while (!IsRunOver()) {
        PlayHand();       // Phase 1: deal and score hand
        EvaluateScore();  // Phase 2 and 3: compute and check threshold
        RunShop();        // Phase 4: shop
        AdvanceRound();   // Phase 5: increase difficulty
    }
}

---

## Reflection

### 1. What is the invariant structure of your game?

The invariant is the phase order inside RunSession::StartRun(). Every round
must follow this exact sequence: deal hand, compute score, check score against
the required threshold, run the shop, then advance the round. This structure
cannot change because each phase produces state that the next phase depends on.
The score must exist before it can be checked. The threshold check must happen
before the shop so the player cannot buy items on a round they already failed.
The round must advance last so difficulty only increases after the player has
had a fair chance to respond in the shop. RunSession exists solely to own and
protect this sequence.

### 2. What parts are mutable?

The mutable parts are everything that affects values or content without touching
the phase sequence. The score formula inside ScoringSystem can change freely,
for example rewarding card pairs with a multiplier instead of simply summing
values. The difficulty scaling factor inside AdvanceRound can be adjusted from
a 1.5 multiplier to a flat addition. The items offered inside ShopSystem and
the effects of modifiers can all change without affecting the loop. Hand size
inside HandGenerator is also mutable. All of these can be modified independently
because they are encapsulated in their own classes, separate from RunSession.

### 3. If you wanted to add a new feature, which class would change?

It depends on the feature. Adding a new modifier type such as a score multiplier
would change ScoringSystem and ShopSystem only. Adding a combo detection rule
that rewards matching cards would change ScoringSystem only. Adding a new shop
item category would change ShopSystem only. In every case RunSession would not
change because the phase order stays the same. This is the main benefit of
separating each responsibility into its own class.

### 4. If you changed the loop order, what would break?

If EvaluateScore ran before PlayHand, there would be no score to check and the
run would end immediately or never end depending on the default value. If RunShop
ran before EvaluateScore, the player could buy modifiers on a round they already
failed, which produces an inconsistent game state. If AdvanceRound ran before
RunShop, the difficulty would increase before the player had any chance to
prepare, making the system unfair. Each phase exists in its position for a
specific reason and moving any one of them breaks the dependencies that follow.
