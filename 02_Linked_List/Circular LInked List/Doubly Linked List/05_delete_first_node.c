#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} data_node;

data_node *add_node(int data) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->prev = ptr;
    ptr->data = data;
    ptr->next = ptr;

    return ptr;
}

data_node *add_at_first(data_node *tail, int data) {
    data_node *ptr = add_node(data);
    data_node *head = tail->next;

    ptr->prev = tail;
    ptr->next = head;
    head->prev = ptr;
    tail->next = ptr;

    return tail;
}

data_node *add_at_last(data_node *tail, int data) {
    data_node *ptr = add_node(data);
    data_node *head = tail->next;

    ptr->prev = tail;
    tail->next = ptr;
    ptr->next = head;
    head->prev = ptr;
    tail = ptr;

    return tail;
}

data_node *delete_first(data_node *tail) {
    data_node *head = tail->next;
    if(tail == NULL) {
        return tail;
    }

    if(head == tail) {
        free(tail);
        tail = NULL;
        return tail;
    }

    tail->next = head->next;
    head->next->prev = tail;
    free(head);
    head = NULL;

    return tail;
}

void print_list(data_node *tail) {
    if(tail == NULL) {
        printf("\nElements not found\n");
    } else {
        data_node *temp = tail->next;
        do {
            printf(" %d", temp->data);
            temp = temp->next;
        } while(temp != tail->next);
    }
}

int main()
{
    data_node *tail = NULL;
    tail = add_node(14);
    tail = add_at_first(tail, 11);
    tail = add_at_first(tail, 16);
    tail = add_at_last(tail, 24);
    tail = add_at_last(tail, 23);

    print_list(tail);

    tail = delete_first(tail);

    printf("\n");

    print_list(tail);

    return 0;
}
