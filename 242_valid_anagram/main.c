/**
 * OK
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_LOWERCASE_ALPHABET 26U

bool isAnagram(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (s_len != t_len) return false;

    int index = 0;
    int* count_arr = (int*)calloc(26, sizeof(int));
    while (index < s_len) {
        count_arr[s[index] - 97] += 1;
        count_arr[t[index] - 97] -= 1;
        index += 1;
    }

    index = NUMBER_OF_LOWERCASE_ALPHABET;
    while(index > 0) {
        printf("count_arr[%u] = %d\n", index - 1, count_arr[index - 1]);
        if (count_arr[index - 1] != 0) return false;
        index -= 1;
    }

    return true;
}

int main() {
    printf("===> The result: %d\n", isAnagram("anagram", "nagaram"));
    return 0;
}