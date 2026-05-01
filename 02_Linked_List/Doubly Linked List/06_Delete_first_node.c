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

    if(head == NULL) {
        return temp;
    }

    data_node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;

    return head;
}

// data_node *delete_node(data_node *head) {
//     data_node *temp = head;
//     head = head->next;
//     free(temp);
//     temp = NULL;
//     return head;
// }

data_node *delete_node(data_node *head) {
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

void print_node(data_node *head) {
    while(head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    data_node *head = NULL;

    head = add_node(head, 40);
    printf("First : %d\n", head->data);

    head = add_end(head, 20);
    printf("Second : %d\n", head->data);

    head = add_end(head, 30);
    printf("Third : %d\n", head->data);

    head = add_end(head, 40);
    head = add_end(head, 50);

    data_node *ptr = head;
    print_node(ptr);

    head = delete_node(head);
    print_node(head);

    return 0;
}
