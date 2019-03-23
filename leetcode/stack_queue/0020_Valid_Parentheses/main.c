#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool isValid(char *s) {
    int n = 0, cap = 100;
    char *stack = (char *) malloc(cap);

    while (*s != '\0') {
        switch (*s) {
            case '(':
            case '[':
            case '{':
                if (n + 1 >= cap) {
                    cap *= 2;
                    stack = realloc(stack, cap);
                }
                stack[n++] = *s;
                break;
            case ')':
                if (stack[--n] != '(') return false;
                break;
            case ']':
                if (stack[--n] != '[') return false;
                break;
            case '}':
                if (stack[--n] != '{') return false;
                break;
            default:
                return false;
        }
        s++;
    }

    free(stack);
    return n == 0;
}

int main() {

    assert(isValid("{{}}()[]") == true);
    assert(isValid("{{}}()]") == false);

    return 0;
}
