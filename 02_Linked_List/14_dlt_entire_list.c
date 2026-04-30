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

data_node *delete_list(data_node *head) {
    data_node *temp = head;
    while(temp != NULL) {
        temp = temp->next;
        free(head);
        head = temp;
    }
    return head;
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

    data_node *ptr = head;

    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    head = delete_list(head);

    if(head == NULL) {
        printf("\nThe list is deleted now..!");
    }

    return 0;
}
