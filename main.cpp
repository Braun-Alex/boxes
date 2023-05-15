#include "s-box.h"

int main() {
    std::array<bool, 8> number = {
            1, 0, 1, 0,
            0, 1, 1, 1
    };
    std::array<bool, 8> result = sBox::substitute(number);
    for (const auto& bit: result) {
        std::cout << bit << " ";
    }
    return 0;
}