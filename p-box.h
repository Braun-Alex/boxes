#pragma once
#include <array>
#include <cmath>

class pBox {
public:
    // Direct transformation
    static std::array<bool, 8> shuffle(std::array<bool, 8> sequence);
    // Inverse transformation
    static std::array<bool, 8> restore(std::array<bool, 8> sequence);
    // Getting of direct P-box
    static std::array<int, 8> getShufflingBox();
    // Setting of direct P-box
    static void setShufflingBox(std::array<int, 8> box);
    // Identifier of P-box
    enum class Box {DIRECT, INVERSE};
private:
    // Transformation with P-box
    static std::array<bool, 8> transform(std::array<bool, 8> sequence, Box option);
    // Updating of inverse P-box
    static void updateInverseShufflingBox();
    inline static std::array<int, 8> directShufflingBox = {0, 2, 4, 6,
                                                            1, 3, 5, 7},
            inverseShufflingBox = directShufflingBox;
};