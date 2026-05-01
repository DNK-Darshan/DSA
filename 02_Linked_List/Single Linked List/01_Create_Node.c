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

    printf("Data: %d\n", head->data);

    return 0;
}
