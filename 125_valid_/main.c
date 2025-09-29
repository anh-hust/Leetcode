#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char* s) {
    // remove the non-alphabet & conert to lower case
    int len = strlen(s);
    char* normalize_str = (char*)malloc((len + 1) * sizeof(char));
    int i;
    bool plus_one;
    int index = 0;
    for (i = 0; i < len; i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            normalize_str[index] = s[i] + 32U;
            index += 1;
            plus_one = true;
        } else if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
            normalize_str[index] = s[i];
            index += 1;
            plus_one = true;
        } else {
            continue;
            plus_one = false;
        }
    }
    plus_one == true ? (normalize_str[index] = '\0') : (normalize_str[index + 1] = '\0');

    len = strlen(normalize_str);
    printf("Normalize: %s\n", normalize_str);

    for (i = 0; i < len / 2; i++) {
        if (normalize_str[i] != normalize_str[len - 1 - i]) {
            plus_one = false;  // reuse plus_one as return val
            goto exit;
        }
    }
    plus_one = true;

exit:
    free(normalize_str);
    return plus_one;
}

int main() {
    char* s = "0P";
    printf("Check palindrome of string \"%s\": %d\n", s, isPalindrome(s));
    return 0;
}