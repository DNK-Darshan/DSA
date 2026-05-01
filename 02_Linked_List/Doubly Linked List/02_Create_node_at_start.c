#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *pre;
    int data;
    struct node *next;
} data_node;

data_node *add_node(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->pre = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}

data_node *add_first(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->pre = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->pre = temp;
    head = temp;
    return head;
}

int main()
{
    data_node *head = NULL;
    data_node *ptr = NULL;

    head = add_node(head, 10);
    head = add_first(head, 20);
    head = add_first(head, 30);

    ptr = head;
 
    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
