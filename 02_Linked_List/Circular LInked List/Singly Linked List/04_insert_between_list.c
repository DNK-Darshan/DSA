#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *addNode(int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

data_node *add_at_first(data_node *tail, int data) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = data;
    ptr->next = tail->next;
    tail->next = ptr;

    return tail;
}

data_node *add_at_end(data_node *tail, int data) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;

    return tail;
}

data_node *add_at_center(data_node *tail, int data, int pos) {
    data_node *head = tail->next;
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = data;
    ptr->next = NULL;

    while(pos > 1) {
        head = head->next;
        pos--;
    }

    ptr->next = head->next;
    head->next = ptr;

    if(ptr == tail) {
        tail = tail->next;
    }

    return tail;
}

void print_list(data_node *tail) {
    data_node *ptr = tail->next;
    do {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
}

int main()
{
    data_node *tail = NULL;
    tail = addNode(14);
    tail = add_at_first(tail, 11);
    tail = add_at_first(tail, 24);
    tail = add_at_end(tail, 16);
    tail = add_at_end(tail, 17);
    tail = add_at_center(tail, 31, 4);

    print_list(tail);

    return 0;
}
