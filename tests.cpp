#include "tests.h"

// S-box must not be empty
TEST(sBox, initialState) {
    std::array<int, 16> serpentBox = sBox::getSerpentBox();
    EXPECT_FALSE(serpentBox.empty());
}

// S-box getter must be deterministic
TEST(sBox, getter) {
    std::array<int, 16> firstSerpentBox = sBox::getSerpentBox(),
                        secondSerpentBox = sBox::getSerpentBox();
    EXPECT_EQ(firstSerpentBox, secondSerpentBox);
}

// Setter must change S-box
TEST(sBox, setter) {
    std::array<int, 16> initialSerpentBox = sBox::getSerpentBox(),
                        tmp = initialSerpentBox;
    auto iterator = std::find(initialSerpentBox.begin(), initialSerpentBox.end(), 3);
    *iterator += 3;
    sBox::setSerpentBox(initialSerpentBox);
    EXPECT_NE(tmp, sBox::getSerpentBox());
}

// Sequential S-box substitution and restoring for a specific data must provide the same data
TEST(sBox, transformation) {
    std::array<bool, 8> data = {1, 0, 1, 0,
                                0, 1, 1, 1};
    std::array<bool, 8> substitutedData = sBox::substitute(data);
    std::array<bool, 8> restoredData = sBox::restore(substitutedData);
    EXPECT_EQ(data, restoredData);
    EXPECT_NE(data, substitutedData);
}

// P-box must not be empty
TEST(pBox, initialState) {
    std::array<int, 8> shufflingBox = pBox::getShufflingBox();
    EXPECT_FALSE(shufflingBox.empty());
}

// P-box getter must be deterministic
TEST(pBox, getter) {
    std::array<int, 8> firstShufflingBox = pBox::getShufflingBox(),
                       secondShufflingBox = pBox::getShufflingBox();
    EXPECT_EQ(firstShufflingBox, secondShufflingBox);
}

// Setter must change P-box
TEST(pBox, setter) {
    std::array<int, 8> initialShufflingBox = pBox::getShufflingBox(),
                       tmp = initialShufflingBox;
    auto iterator = std::find(initialShufflingBox.begin(), initialShufflingBox.end(), 3);
    *iterator += 3;
    pBox::setShufflingBox(initialShufflingBox);
    EXPECT_NE(tmp, pBox::getShufflingBox());
}

// Sequential P-box shuffling and restoring for a specific data must provide the same data
TEST(pBox, transformation) {
    std::array<bool, 8> data = {1, 0, 1, 0,
                                0, 1, 1, 1};
    std::array<bool, 8> shuffledData = pBox::shuffle(data);
    std::array<bool, 8> restoredData = pBox::restore(shuffledData);
    EXPECT_EQ(data, restoredData);
    EXPECT_NE(data, shuffledData);
}

// Sequential box direct and inverse transformations for a specific data must provide the same data
TEST(boxes, sequentialTransformation) {
    std::array<bool, 8> data = {1, 0, 1, 0,
                                0, 1, 1, 1};
    std::array<bool, 8> transformedData = pBox::shuffle(sBox::substitute(data));
    std::array<bool, 8> restoredData = sBox::restore(pBox::restore(transformedData));
    EXPECT_EQ(data, restoredData);
    EXPECT_NE(data, transformedData);
}

// Random box direct and inverse transformations for a specific data must not provide the same data
TEST(boxes, randomTransformation) {
    std::array<bool, 8> data = {1, 0, 1, 0,
                                0, 1, 1, 1};
    std::array<bool, 8> transformedData = pBox::shuffle(sBox::substitute(data));
    std::array<bool, 8> restoredData = pBox::restore(sBox::restore(transformedData));
    EXPECT_NE(data, restoredData);
    EXPECT_NE(data, transformedData);
}