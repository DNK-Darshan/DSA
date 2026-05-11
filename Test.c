#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *add_node(int data) {
    data_node *temp = NULL;
    temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

data_node *add_at_end(data_node *head, int data) {
    data_node *ptr = NULL;
    ptr = add_node(data);

    while(head->next != NULL) {
        head = head->next;
    }
    head->next = ptr;
}

data_node *reverse_list(data_node *head) {
    data_node *prev = NULL;
    data_node *next = NULL;

    while(head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

void print(data_node *head) {
    data_node *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    data_node * head = NULL;
    head = add_node(14);

    add_at_end(head, 11);
    add_at_end(head, 31);
    add_at_end(head, 24);

    print(head);

    head = reverse_list(head);

    print(head);

    return 0;
}
