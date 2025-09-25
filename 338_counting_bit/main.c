/**
 * OK
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int* ret = (int*)malloc((n + 1) * sizeof(int));
    int count_1;
    int mod;

    for (int i = 0; i <= n; i++) {
        count_1 = 0;
        mod = i;
        while (mod != 0) {
            if (mod % 2 == 1) count_1 += 1;
            mod = mod / 2;
        }
        ret[i] = count_1;
    }

    *returnSize = n + 1;
    return ret;
}

int main(){
    int n = 5;
    int* ret;
    int ret_size;
    ret = countBits(n, &ret_size);

    free(ret);
    return 0;
}