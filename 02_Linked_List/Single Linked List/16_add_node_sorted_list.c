#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *add_node(int data) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = data;
    ptr->next = NULL;

    return ptr;
}

data_node *add_at_first(data_node *head, int data) {
    data_node *ptr = add_node(data);
    data_node *temp = head;

    ptr->next = temp;
    head = ptr;

    return head;
}

data_node *add_at_last(data_node *head, int data) {
    data_node *ptr = add_node(data);
    data_node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr;

    return head;    
}

data_node *insert_node(data_node *head, int data) {
    data_node *ptr = add_node(data);
    int key = ptr->data;
    
    if(head == NULL || key < head->data) {
        ptr->next = head;
        head = ptr;
    } else {
        data_node *temp = head;
        while(temp != NULL && temp->next->data < key) {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return head;
}

void print_list(data_node *head) {
    data_node *temp = head;
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    data_node *head = NULL;
    head = add_node(45);
    head = add_at_first(head, 24);
    head = add_at_last(head, 56);
    head = add_at_last(head, 100);

    head = insert_node(head, 75);
    print_list(head);

    return 0;
}
