#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *add_at_end(data_node *head, int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = NULL;

    head->next = temp;
    return temp;
}

data_node *reverse(data_node *head) {
    data_node *previous = NULL;
    data_node *current = head;
    data_node *nextNode = head;

    while(nextNode != NULL) {
        nextNode = nextNode->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    head = previous;
    return head;
}

int main()
{
    data_node *head = NULL;
    head = (data_node *)malloc(sizeof(data_node));
    head->data = 10;
    head->next = NULL;

    data_node *ptr = head;
    ptr = add_at_end(ptr, 20);
    ptr = add_at_end(ptr, 30);
    ptr = add_at_end(ptr, 40);
    ptr = add_at_end(ptr, 50);

    ptr = head;

    ptr = reverse(ptr);

    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
