#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define IS_SAME_STRING(X, Y) (!strcmp((X), (Y)))

bool is_match_close_parenthese(const char *the_open, const char *the_close) {
    if (IS_SAME_STRING(the_open, '(') && IS_SAME_STRING(the_close, ')')) {
        return true;
    } else if (IS_SAME_STRING(the_open, '[') && IS_SAME_STRING(the_close, ']')) {
        return true;
    } else if (IS_SAME_STRING(the_open, '{') && IS_SAME_STRING(the_close, '}')) {
        return true;
    } else {
        return false;
    }
}

// push & pop function will update: stack value, index and top of the stack
void push(char *stack, int *stack_index, char *top) {
    
}

void pop(char *stack, int *stack_index, char *top) {
}

bool isValid(char *s) {
    char *stack = (char *)malloc(strlen(s) * sizeof(char));
    char *top = stack;
    bool ret = true;

    int i = 0;
    int stack_i = 0;
    for (i; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[stack_i++] = s[i];
            top = stack + stack_i;
        } else {
            // assume the input string just have the open and close parenthese
            if (is_match_close_parenthese(top, s[i]))
                stack_i -= 1;
            else {
                ret = false;
                break;
            }
        }
    }

    if (strlen(stack) != 0) ret = false;

    free(stack);
    return ret;
}

int main() {
    char *s = "([)]";

    return 0;
}