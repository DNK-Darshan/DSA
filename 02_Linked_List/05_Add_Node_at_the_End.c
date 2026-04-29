#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add_end(struct node *head, int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    while(head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
}

void print(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = 20;
    second->next = NULL;
    head->next = second;

    second = (struct node *)malloc(sizeof(struct node));
    second->data = 30;
    second->next = NULL;
    head->next->next = second;

    add_end(head, 40);
    print(head);

    return 0;
}
