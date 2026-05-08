#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

int isEmpty(data_node **top) {
    if(top == NULL)
        return 1;
    else 
        return 0;
}

data_node *push(int data, data_node **top) {
    data_node *ptr = NULL;
    ptr = (data_node *)malloc(sizeof(data_node));
    if(ptr == NULL) {
        printf("The stack is overflow\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = *top;
    *top = ptr;
}

data_node *pop(data_node **top) {
    data_node *temp = NULL;
    int val;
    if(isEmpty(top)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    temp = *top;
    val = temp->data;
    *top = (*top)->next;
    free(temp);
    temp = NULL;
    return val;
}

void print(data_node **top) {
    data_node *temp = NULL;
    temp = *top;
    while (temp) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_stack(data_node **top) {
    data_node *top1 = NULL;
    data_node *top2 = NULL;

    // Pushing onto temp stack 1
    while(*top != NULL) {
        push(pop(top), &top1);
    }

    // Pushing onto temp stack 2
    while(top1 != NULL) {
        push(pop(top1), &top2);
    }

    // Pushing onto original stack
    while(top2 != NULL) {
        push(pop(&top2), top);
    }
}

int main()
{
    data_node *top = NULL;
    
    push(1, &top);
    push(2, &top);
    push(3, &top);

    reverse_stack(&top);

    print(&top);

    return 0;
}

/*

We can't used the global pointer to declare the top pointers because of we passed the multiple pointer to the push function and push only take a top pointers we have a three stack so we want to passed the multiple pointers to the push so we must it define to the locally.

*/