#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
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

data_node *delete_last(data_node *head) {
    if(head == NULL) {
        printf("\nThe list is Empty!");
    } else if(head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        data_node *temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
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
    add_at_end(head, 70);

    head = delete_last(head);

    data_node *ptr = head;

    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
