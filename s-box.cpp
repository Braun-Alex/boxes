#include "s-box.h"

// Direct transformation with direct S-box
std::array<bool, 8> sBox::substitute(std::array<bool, 8> sequence) {
    return transform(sequence, Box::DIRECT);
}

// Inverse transformation with inverse S-box
std::array<bool, 8> sBox::restore(std::array<bool, 8> sequence) {
    // Just in case, inverseSerpentBox has to be updated
    updateInverseSerpentBox();
    return transform(sequence, Box::INVERSE);
}

// Getter for directSerpentBox
std::array<int, 16> sBox::getSerpentBox() {
    return directSerpentBox;
}

// Setter for directSerpentBox
void sBox::setSerpentBox(std::array<int, 16> box) {
    directSerpentBox = box;
}

// Transformation of 8-bit data with two 4-bit nibbles and specified type of S-box
std::array<bool, 8> sBox::transform(std::array<bool, 8> sequence, Box option) {
    std::array<bool, 4> leftNibble {}, rightNibble {};
    // Dividing 8-bit data into two 4-bit nibbles
    for (int i = 0; i < 4; i++) {
        leftNibble[i] = sequence[i];
        rightNibble[i] = sequence[i + 4];
    }
    int leftPosition = 0, rightPosition = 0, multiplier = 1, leftNumber, rightNumber;
    // Converting binary numbers to decimal numbers for finding necessary indices in S-box
    for (int i = 4; i > 0; i--) {
        for (int j = i - 1; j > 0; j--) {
            multiplier *= 2;
        }
        leftPosition += leftNibble[4 - i] * multiplier;
        rightPosition += rightNibble[4 - i] * multiplier;
        multiplier = 1;
    }
    if (option == Box::DIRECT) {
        leftNumber = directSerpentBox[leftPosition];
        rightNumber = directSerpentBox[rightPosition];
    } else {
        leftNumber = inverseSerpentBox[leftPosition];
        rightNumber = inverseSerpentBox[rightPosition];
    }
    int i = 3;
    std::array<bool, 8> result {};
    result.fill(false);
    // Converting decimal left nibble into binary 4-bit number
    while (leftNumber > 0) {
        result[i] = leftNumber % 2;
        leftNumber /= 2;
        --i;
    }
    i = 7;
    // Converting decimal right nibble into binary 4-bit number
    while (rightNumber > 0) {
        result[i] = rightNumber % 2;
        rightNumber /= 2;
        --i;
    }
    return result;
}

// Updating inverse Serpent S-box with using of algorithm of finding inverse element in GF(16)
void sBox::updateInverseSerpentBox() {
    size_t size = inverseSerpentBox.size();
    for (int i = 0; i < size; i++) {
        if (directSerpentBox[i] != 0) {
            directSerpentBox[i] = inverse(directSerpentBox[i], 16);
        }
    }
}