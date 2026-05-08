#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

int isEmpty() {
    if(top == -1)
        return 1;
    else 
        return 0;
}

int isFull() {
    if(top == MAX - 1) 
        return 1;
    else 
        return 0;
}

int match_char(char a, char b) {
    if(a == '[' && b == ']')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    return 0;
}

void push(char c) {
    if(isFull()) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
    printf("%c is pushed into the stack \n", c);
}

char pop() {
    char c;
    if(isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top--;
    return c;
}

int check_balanced(char *s) {
    char temp;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            push(s[i]);

        if(s[i] == ']' || s[i] == '}' || s[i] == ')') {
            if(isEmpty()) {
                printf("Right brackets are more then the left\n");
                return 0;
            } else {
                temp = pop();
                if(!match_char(temp, s[i])) {
                    printf("Mismatch brackets\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty()) {
        printf("Brackets are well balanced\n");
        return 1;
    } else {
        printf("Left brackets are more then the right\n");
        return 0;
    }
}

int main()
{
    char expr[MAX];
    int balanced;

    printf("Enter the Expression: ");
    gets(expr);

    balanced = check_balanced(expr);

    if(balanced == 1)
        printf("The expression is valid\n");
    else 
        printf("The expression is not valid\n");

    return 0;
}
