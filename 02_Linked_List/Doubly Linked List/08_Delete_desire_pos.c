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

data_node *delete_node(data_node *head) {
    data_node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
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

data_node *delete_pos(data_node *head, int pos) {
    data_node *temp = head;
    data_node *temp2 = NULL;

    if(pos == 0) {
        head = delete_node(head);
        return head;
    }

    while(pos > 0) {
        temp = temp->next;
        pos--;
    }

    if(temp->next == NULL) {
        head = delete_last(head);
        return head;
    } else {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
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

    head = add_node(head, 90);
    head = add_end(head, 70);
    head = add_end(head, 20);
    head = add_end(head, 30);
    head = add_end(head, 50);

    print_node(head);

    head = delete_pos(head, 3);

    print_node(head);

    return 0;
}
