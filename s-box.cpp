#include "s-box.h"

std::array<bool, 8> sBox::substitute(std::array<bool, 8> sequence) {
    std::array<bool, 4> leftNibble {}, rightNibble {};
    for (int i = 0; i < 4; i++) {
        leftNibble[i] = sequence[i];
        rightNibble[i] = sequence[i + 4];
    }
    int leftPosition = 0, rightPosition = 0, multiplier = 1, leftNumber, rightNumber;
    for (int i = 4; i > 0; i--) {
        for (int j = i - 1; j > 0; j--) {
            multiplier *= 2;
        }
        leftPosition += leftNibble[4 - i] * multiplier;
        rightPosition += rightNibble[4 - i] * multiplier;
        multiplier = 1;
    }
    leftNumber = serpentBox[leftPosition];
    rightNumber = serpentBox[rightPosition];
    int i = 3;
    std::array<bool, 8> result {};
    result.fill(false);
    while (leftNumber > 0) {
        result[i] = leftNumber % 2;
        leftNumber /= 2;
        --i;
    }
    i = 7;
    while (rightNumber > 0) {
        result[i] = rightNumber % 2;
        rightNumber /= 2;
        --i;
    }
    return result;
}