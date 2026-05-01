#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 14;
    head->next = NULL;

    struct node *second = NULL;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = 28;
    second->next = NULL;

    head->next = second;

    printf("Data: %d\n", head->next->data);

    return 0;
}
