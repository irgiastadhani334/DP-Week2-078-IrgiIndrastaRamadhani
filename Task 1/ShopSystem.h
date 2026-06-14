#ifndef SHOP_SYSTEM_H
#define SHOP_SYSTEM_H

#include <iostream>

class ShopSystem {
public:
    void offer(int& money) {
        int cost = 2;
        std::cout << "[SHOP] offered: Bonus(+2) cost " << cost << "\n";
        if (money >= cost) {
            std::cout << "[SHOP] skipped\n";
        } else {
            std::cout << "[SHOP] not enough money, skipped\n";
        }
    }
};

#endif
