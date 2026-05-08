#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *top = NULL;

int isEmpty() {
    if(top == NULL)
        return 1;
    else 
        return 0;
}

void push(int data) {
    data_node *ptr = NULL;
    ptr = (data_node *)malloc(sizeof(data_node));
    if(ptr == NULL) {
        printf("The stack is overflow\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = top;
    top = ptr;
}

int pop() {
    data_node *temp = NULL;
    int val;
    if(isEmpty()) {
        printf("The stack is underflow\n");
        return -1;
    }
    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);
    temp = NULL;
    return val;
}

int peek() {
    if(isEmpty()) {
        printf("The stack is underflow\n");
        return -1;
    }
    return top->data;
}

void print() {
    data_node *temp = top;
    if(isEmpty()) {
        printf("The stack is underflow\n");
        return -1;
    }
    while (temp) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");    
}

int main()
{
    int choice, data;
    while(1) {
        printf("\n \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the element of stack\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            int val = pop();
            if(val != -1){
                printf("%d is popped out from stack\n", val);
            }
            break;

        case 3:
            if(peek() != -1)
                printf("The top most element of the stack is %d\n", peek());
            break;

        case 4:
            print();
            break;

        case 5:
            printf("Your choice is quit a application\n");
            exit(1);

        default:
            printf("Please choose a right number in above list\n");
            break;
        }
    }

    return 0;
}
