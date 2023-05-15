#include "inverse.h"

int inverse(int a, int n) {
    int t = 0, r = n, newT = 1, newR = a, quotient, tmp;
    while (newR != 0) {
        quotient = r / newR;
        tmp = t;
        t = newT;
        newT = tmp - quotient * newT;
        tmp = r;
        r = newR;
        newR = tmp - quotient * newR;
    }
    if (r > 1) {
        return a;
    } else if (t < 0) {
        t += n;
    }
    return t;
}