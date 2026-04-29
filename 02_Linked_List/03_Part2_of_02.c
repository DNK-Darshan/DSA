#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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

    return 0;
}
