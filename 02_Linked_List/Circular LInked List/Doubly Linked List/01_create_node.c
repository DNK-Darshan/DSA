#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} data_node;

data_node *createNode(int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;

    return temp;
}

int main()
{
    int data = 14;
    data_node *tail = NULL;
    tail = createNode(data);

    printf("%d", tail->data);

    return 0;
}
