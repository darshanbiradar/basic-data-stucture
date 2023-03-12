#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 30

typedef struct {
    char stk[size];
    int top;
} stack;

stack s;

void push(char op) {
    s.stk[++(s.top)] = op;
}

char pop() {
    return s.stk[(s.top)--];
}

int match(char a, char b) {
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    return 0;
}

int check(char *expr) {
    int i;
    char temp;
    for (i = 0; i < strlen(expr); i++) {
        if (expr[i] == '[' || expr[i] == '{' || expr[i] == '(')
            push(expr[i]);
        else if (expr[i] == ']' || expr[i] == '}' || expr[i] == ')') 
        {
            if (s.top == -1) 
            {
                printf("Right parenthesis are more \n");
                return 0;
            } else 
            {
                temp = pop();
                if (!match(temp, expr[i]))
                {
                    printf("Mismatch\n%c and %c\n", temp, expr[i]);
                    return 0;
                }
            }
        }
    }
    if (s.top == -1) 
    {
        printf("Balanced parentheses\n");
        return 1;
    } 
    else {
        printf("Left parentheses are more\n");
        return 0;
    }
}

int main() {
    s.top = -1;
    char expr[size];
    int valid;
    printf("Enter the brackets\n");
    scanf("%s", expr);
    valid = check(expr);
    if (valid == 1)
        printf("Balanced\n");
    else
        printf("Unbalanced\n");
    return 0;
}
