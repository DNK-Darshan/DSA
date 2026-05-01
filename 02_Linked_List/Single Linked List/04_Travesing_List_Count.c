#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void count_of_nodes(struct node *head) {
    int count = 0;
    if(head == NULL) {
        printf("List is empty.\n");
    }

    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    printf("Number of nodes in the list: %d\n", count);
}

void print_Elements(struct node *head) {
    if(head == NULL) {
        printf("List is empty.\n");
    }

    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 14;
    head->next = NULL;

    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = 28;
    second->next = NULL;
    head->next = second;

    second = (struct node *)malloc(sizeof(struct node));
    second->data = 42;
    second->next = NULL;

    head->next->next = second;

    printf("Data: %d\n", head->next->next->data);

    count_of_nodes(head);
    print_Elements(head);

    return 0;
}
