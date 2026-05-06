#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack[MAX];
int first = -1;

int isFull() {
    if(first == MAX -1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if(first == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int data) {
    if(isFull()) {
        printf("The stack is overslow\n");
        return;
    }

    first++;
    for(int i = first; i > 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = data;
    printf("%d is push the stack\n", data);
}

void pop() {
    int value;
    if(isEmpty()) {
        printf("The stack is underflow\n");
        return;
    }
    
    value = stack[0];
    for(int i = 0; i < first; i++) {
        stack[i] = stack[i + 1];
    }
    printf("%d is popped out the stack\n", value);
    first--;
}

int peek() {
    if(isEmpty()) {
        printf("The stack is underflow\n");
        return -1;
    }
    return stack[0];
}

void print() {
    if(first == -1) {
        printf("The stack is underflow\n");
        return;
    }
    for(int i = 0; i <= first; i++) {
        printf(" %d", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;
    while(1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Top Element\n");
        printf("4. Print all the Element in stack\n");
        printf("5. Quite\n");
        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            if(peek() != -1)
                printf("The top most element of the stack is %d\n", peek());
            break;

        case 4:
            print();
            break;

        case 5: 
            printf("You quite the app\n");
            exit(1);
        
        default:
            printf("Wrong choice please enter the valid number\n");
        }
    }
    
    return 0;
}
