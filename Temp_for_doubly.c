#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *pre;
    int data;
    struct node *next;
} data_node;

data_node *add_node(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));

    temp->data = data;
    temp->next = NULL;
    temp->pre = NULL;

    // Case 1: Empty list
    if (head == NULL) {
        return temp;
    }

    // Case 2: Traverse to last node
    data_node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Attach new node
    ptr->next = temp;
    temp->pre = ptr;

    return head;  // return original head
}

void display_list(data_node *head) {
    data_node *ptr = head;
    while (ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    data_node *head = NULL;

    head = add_node(head, 10);
    head = add_node(head, 20);
    head = add_node(head, 30);

    display_list(head);

    return 0;
}