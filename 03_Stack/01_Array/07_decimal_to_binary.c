#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isFull() {
    if(top == MAX -1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int data) {
    if(isFull()) {
        printf("The stack is overflow\n");
        return;
    }
    top++;
    stack[top] = data;
}

int pop() {
    int value;
    if(isEmpty()) {
        printf("Stack is underflow\n");
        exit(1);
    }
    value = stack[top];
    top--;
    return value;
}

void dec2bin(int n) {
    while (n != 0) {
        push(n%2);
        n = n / 2;
    }
}

void print() {
    if(isEmpty()) {
        printf("Stack is underflow");
        return;
    }
    while(!isEmpty()) {
        printf(" %d", pop());
    }
    printf("\n");
}

int main()
{
    int dec;

    printf("Enter the decimal number: ");
    scanf("%d", &dec);

    dec2bin(dec);
    print();
    return 0;
}
