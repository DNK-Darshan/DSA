#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int arr[MAX];
int top = -1;

void push(int data) {
    if(top == MAX - 1) {
        printf("\nThe Stack is Overflow %d is not push\n", data);
        return;
    }
    top++;
    arr[top] = data;
    printf("%d pushed into stack\n", data);
}

int pop() {
    if(top == -1) {
        printf("The stack is underflow\n");
        return;
        // exit(1); // We don't won't to return an integer so we can write this function exit(1) means abnormal termination of program.
    }
    printf("\n%d is popped from the stack\n", arr[top]);
    top--;
}

void print_stack() {
    if(top == -1) {
        printf("The stack is empty\n");
    }

    for(int i = top; i >= 0; i--) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    print_stack();

    pop();
    print_stack();

    pop();
    print_stack();

    return 0;
}
