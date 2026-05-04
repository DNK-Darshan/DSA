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
    data_node *new_ptr = add_node(data);
    data_node *head = tail->next;

    new_ptr->prev = tail;
    new_ptr->next = head;
    head->prev = new_ptr;
    tail->next = new_ptr;

    return tail;
}

void print_list(data_node *tail) {
    if(tail == NULL) {
        printf("\nElements not found");
    } else {
        data_node *temp = tail->next;
        do {
            printf(" %d", temp->data);
            temp = temp->next;
        } while(temp != tail->next);
    }
    printf("\n");
}

int main()
{
    data_node *tail = NULL;
    tail = add_node(14);
    tail = add_at_first(tail, 11);
    tail = add_at_first(tail, 16);

    print_list(tail);

    return 0;
}
