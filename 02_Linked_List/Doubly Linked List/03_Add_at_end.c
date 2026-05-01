#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} data_node;

data_node *add_node(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}

data_node *add_first(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;
}

data_node *add_end(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    data_node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;

    return head;
}

int main()
{    
    data_node *head = NULL;
    data_node *ptr = NULL;

    head = add_node(head, 10);
    head = add_first(head, 20);
    head = add_end(head, 30);

    ptr = head;
    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
