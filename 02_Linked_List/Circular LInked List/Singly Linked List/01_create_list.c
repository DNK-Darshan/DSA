#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *createList(int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

int main()
{
    int data = 14;
    
    data_node *tail = NULL;
    tail = createList(data);

    printf("%d", tail->data);

    return 0;
}
