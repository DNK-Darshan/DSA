#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

void *add_at_end(data_node *head, int data) {
    data_node *temp = NULL;
    temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = NULL;

    while(head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
}

void *add_at_center(data_node *head, int data, int pos) {
    data_node *ptr = head;
    data_node *temp = NULL;
    temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = NULL;

    pos--;
    while(pos != 0) {
        ptr = ptr->next;
        pos--;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

int main()
{
    data_node *head = NULL;
    head = (data_node *)malloc(sizeof(data_node));
    head->data = 10;
    head->next = NULL;

    add_at_end(head, 20);
    add_at_end(head, 30);
    add_at_end(head, 40);
    add_at_end(head, 50);
    add_at_end(head, 60);
    add_at_end(head, 70);

    int data = 14, pos = 4;
    add_at_center(head, data, pos);

    data_node *ptr = head;

    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
