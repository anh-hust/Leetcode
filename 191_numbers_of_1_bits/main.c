#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int hammingWeight(int n) {
    int ret = 0;

    int i = sizeof(n) * 8 - 1;
    for (; i >= 0; i--) {
        if (((n >> i) & 1U) == 1) ret += 1;
    }

    return ret;
}

int main() {
    int n = 9;
    printf("Number of 1 bits of nummber %d: %d", n, hammingWeight(n));
    return 0;
}