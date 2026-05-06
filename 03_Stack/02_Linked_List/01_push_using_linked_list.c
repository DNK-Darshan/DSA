#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL;

void push(int data) {
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL) {
        printf("Stack Overflow");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
}

void print() {
    struct node *temp;
    temp = top;
    printf("The stack elements are: ");

    while(temp) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int data, choice;
    while(1) {
        printf("\n \n");
        printf("1. Push\n");
        printf("2. Print\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;
        
        case 2:
            print();
            break;
        
        case 3:
            exit(1);
        
        default:
            break;
        }
    }
    return 0;
}
