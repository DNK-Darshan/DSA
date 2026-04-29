#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// struct node *add_at_first(struct node *head, int data) {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->next = NULL;

//     temp->next = head;
//     head = temp;
//     return head;
// }


struct node *add_at_first(struct node **head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    temp->next = *head;
    *head = temp;
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 20;
    ptr->next = NULL;
    
    head->next = ptr;

    int data = 30;

    // This head is pass by value and we are returning the new head after insertion
    // head = add_at_first(head, data);

    add_at_first(&head, data);

    ptr = head;

    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
