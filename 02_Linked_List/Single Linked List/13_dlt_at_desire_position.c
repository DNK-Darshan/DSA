#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

void *add_at_end(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = NULL;

    while(head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
}

void delete_node(data_node **head, int position) {
    data_node *cureent = *head;
    data_node *previous = *head;

    if(*head == NULL) {
        printf("\nThe List is empty!");
    } else if(position == 1) {
        *head = cureent->next;
        free(cureent);
        cureent = NULL;
    } else {
        while(position != 0) {
            previous = cureent;
            cureent = cureent->next;
            position--;
        }
        previous->next = cureent->next;
        free(cureent);
        cureent = NULL;
    }
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

    int pos = 3;
    delete_node(&head, pos);

    data_node *ptr = head;

    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
