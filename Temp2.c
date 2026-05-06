#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

// Push function
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;
    printf("%d pushed into stack\n", value);
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underfl1ow\n");
        return;
    }

    printf("%d popped from stack\n", stack[top]);
    top--;
}

// Peek function
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();
    display();

    pop();
    pop();
    pop();  // Underflow case

    return 0;
}