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

data_node *delete_last(data_node *head) {
    data_node *temp = head, *temp2 = NULL;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);

    return head;
}

void print_node(data_node *head) {
    data_node *ptr = head;
    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    data_node *head = NULL;

    head = add_node(head, 50);
    head = add_end(head, 90);
    head = add_end(head, 40);
    head = add_end(head, 80);

    print_node(head);

    head = delete_last(head);

    print_node(head);

    return 0;
}
