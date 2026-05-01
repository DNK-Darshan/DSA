#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} data_node;

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

data_node *createList(data_node *head) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n == 0) {
        return head;
    }

    for(int i = 1; i <= n; i++) {
        printf("Enter the elements for the nodes %d: ", i);
        scanf("%d", &data);
        head = add_end(head, data);
    }
    return head;
}

int main()
{
    data_node *head = NULL;
    data_node *ptr = NULL;

    head = createList(head);

    ptr = head;
    while(ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}
