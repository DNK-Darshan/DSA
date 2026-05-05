#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} data_node;

data_node *add_node(int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;

    return temp;
}

data_node *add_at_first(data_node *tail, int data) {
    data_node *ptr = add_node(data);
    data_node *head = tail->prev;

    ptr->prev = tail->next;
    ptr->next = head;
    head->prev = ptr;
    tail->next = ptr;

    return tail;
}

data_node *add_at_last(data_node *tail, int data) {
    data_node *ptr = add_node(data);
    data_node *head = tail->next;

    tail->next = ptr;
    ptr->prev = tail;
    ptr->next = head;
    head->prev = ptr;
    tail = ptr;

    return tail;
}

data_node *delete_position(data_node *tail, int pos) {
    data_node *temp = tail->next;
    while (pos > 0) {
        temp = temp->next;
        pos--;
    }

    data_node *temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    temp = NULL;

    if(temp == tail) {
        tail = temp2;
    }

    return tail;
}

void print_list(data_node *tail) {
    if(tail == NULL) {
        printf("Empty linked list");
    } else {
        data_node *tmp = tail->next;
        do{
            printf(" %d", tmp->data);
            tmp = tmp->next;
        } while(tmp != tail->next);
    }
}

int main()
{
    data_node *tail = NULL;
    tail = add_node(14);
    tail = add_at_first(tail, 11);
    tail = add_at_last(tail, 21);
    tail = add_at_last(tail, 31);
    tail = add_at_last(tail, 16);
    print_list(tail);

    printf("\n");
    tail = delete_position(tail, 3);
    print_list(tail);

    return 0;
}
