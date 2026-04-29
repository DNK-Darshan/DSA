#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *add_at_end(struct node *ptr, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    ptr->next = temp;
    return temp;
}

struct node *add_at_middle(struct node *head, int data, int position) {
    struct node *ptr = head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));

    ptr2->data = data;
    ptr2->next = NULL;

    position--;
    while(position != 0) {
        ptr = ptr->next;
        position--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 20);
    ptr = add_at_end(ptr, 30);
    
    int data = 40, position = 2;
    
    add_at_middle(head, data, position);
    ptr = head;

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
