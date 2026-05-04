#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *createNode(int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

data_node *add_at_first(data_node *tail, int data) {
    data_node *newP = (data_node *)malloc(sizeof(data_node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;

    return tail;
}

void printList(data_node *tail) {
    data_node *ptr = tail->next;
    do {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
} 

int main()
{
    data_node *tail = NULL;
    tail = createNode(14);
    tail = add_at_first(tail, 11);

    printList(tail);
    // printf("%d", tail->next->data);

    return 0;
}
