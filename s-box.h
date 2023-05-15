#pragma once
#include "inverse.h"
#include <array>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>

class sBox {
public:
    // Direct transformation
    static std::array<bool, 8> substitute(std::array<bool, 8> sequence);
    // Inverse transformation
    static std::array<bool, 8> restore(std::array<bool, 8> sequence);
    // Getting of direct Serpent S-box
    static std::array<int, 16> getSerpentBox();
    // Setting of direct Serpent S-box
    static void setSerpentBox(std::array<int, 16> box);
    // Identifier of S-box
    enum class Box {DIRECT, INVERSE};
private:
    // Transformation with S-box
    static std::array<bool, 8> transform(std::array<bool, 8> sequence, Box option);
    // Updating inverse Serpent S-box
    static void updateInverseSerpentBox();
    // This particular S-box is used in the Serpent cryptosystem
    inline static std::array<int, 16> directSerpentBox = {3, 8, 15, 1,
                                         10, 6, 5, 11,
                                         14, 13, 4, 2,
                                         7, 0, 9, 12},
                                      inverseSerpentBox = directSerpentBox;
};