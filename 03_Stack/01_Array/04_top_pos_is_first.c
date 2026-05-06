#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int first = -1;

void push(int data) {
    first++;
    for(int i = first; i > 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = data;
}

void print() {
    if(first == -1) {
        printf("The stack is underflow\n");
        exit(1);
    }
    for(int i = 0; i <= first; i++) {
        printf(" %d", stack[i]);
    }
    printf("\n");
}

int main()
{
    push(14);
    push(11);
    push(31);
    print();
    return 0;
}
