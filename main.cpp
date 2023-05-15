#include "p-box.h"
#include <iostream>

int main() {
    std::array<bool, 8> number = {
            1, 0, 1, 0,
            0, 1, 1, 1
    };
    std::array<bool, 8> result = pBox::shuffle(number);
    for (const auto &bit: result) {
        std::cout << bit;
    }
    std::cout << std::endl;
    result = pBox::restore(result);
    for (const auto &bit: result) {
        std::cout << bit;
    }
    return 0;
}