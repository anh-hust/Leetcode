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

bool is_open_parenthese(const char *value) {
    if (*value == '(' || *value == '{' || *value == '[') return true;
    return false;
}

// push & pop function will update: stack value, index and top of the stack
// true mean the action be done succesfully
bool push(char *stack, const int stack_max, int *const stack_index, char *top, const char *value) {
    if (*stack_index == stack_max) return false;
    stack[*stack_index] = *value;
    *stack_index += 1;
    top += 1;
    return true;
}

bool pop(char *stack, int *const stack_index, char *top) {
    if (top == stack) return false;
    *stack_index -= 1;
    top -= 1;
    return true;
}

bool isValid(char *s) {
    int input_len = strlen(s);
    char *stack = (char *)malloc(input_len * sizeof(char));
    char *top = stack;
    bool ret = true;

    int i = 0;
    int stack_i = 0;
    int action_ret = false;
    for (i; i < input_len; i++) {
        if (is_open_parenthese(s[i])) {
            action_ret = push(stack, input_len, &stack_i, top, s[i]);
        } else {
            // assume the input string just has the open and close parenthese
            if (is_match_close_parenthese(top, s[i]))
                action_ret = pop(stack, &stack_i, top);
            else {
                ret = false;
                break;
            }
        }
        if (action_ret == false) {
            ret = false;
            break;
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