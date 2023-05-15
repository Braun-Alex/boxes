#pragma once
#include <array>
#include <iostream>
#include <algorithm>
#include <cmath>

class sBox {
public:
    static std::array<bool, 8> substitute(std::array<bool, 8> sequence);
    static std::array<bool, 8> restore(std::array<bool, 8> bitset);
private:
    // This particular S-box is used in the Serpent cryptosystem
    inline static std::array<int8_t, 16> serpentBox = {3, 8, 15, 1,
                                         10, 6, 5, 11,
                                         14, 13, 4, 2,
                                         7, 0, 9, 12};
};