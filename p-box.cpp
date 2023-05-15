#include "p-box.h"

// Direct transformation with direct P-box
std::array<bool, 8> pBox::shuffle(std::array<bool, 8> sequence) {
    return transform(sequence, Box::DIRECT);
}

// Inverse transformation with inverse P-box
std::array<bool, 8> pBox::restore(std::array<bool, 8> sequence) {
    // Just in case, inverseShufflingBox has to be updated
    updateInverseShufflingBox();
    return transform(sequence, Box::INVERSE);
}

// Getter for directShufflingBox
std::array<int, 8> pBox::getShufflingBox() {
    return directShufflingBox;
}

// Setter for directShufflingBox
void pBox::setShufflingBox(std::array<int, 8> box) {
    directShufflingBox = box;
}

// Transformation with P-box
std::array<bool, 8> pBox::transform(std::array<bool, 8> sequence, Box option) {
    std::array<bool, 8> result {};
    if (option == Box::DIRECT) {
        for (int i = 0; i < 8; i++) {
            result[directShufflingBox[i]] = sequence[i];
        }
    } else {
        for (int i = 0; i < 8; i++) {
            result[inverseShufflingBox[i]] = sequence[i];
        }
    }
    return result;
}

// Updating of inverse P-box
void pBox::updateInverseShufflingBox() {
    size_t size = inverseShufflingBox.size();
    for (int i = 0; i < size; i++) {
        inverseShufflingBox[directShufflingBox[i]] = i;
    }
}