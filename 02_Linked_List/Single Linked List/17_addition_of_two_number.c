/*

This code is still pendding it is in progress

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *reversal(data_node *head) {
    if(head == NULL) {
        return head;
    }
    data_node *current = NULL;
    data_node *next = head->next;
    head->next = NULL;

    while(next != NULL) {
        current = next;
        next = next->next;
        current->next = head;
        head = current;
    }

    return head;
}

data_node *add_node(data_node *head, int val) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = val;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;
    return head;
}

data_node *createLL(data_node *head, int n) {
    while(n != 0) {
        head = add_node(head, n%10);
        n = n / 10;
    }
    return head;
}

void print_list(data_node *head) {
    data_node *temp = head;
    if(head == NULL) {
        printf("No Number Available");
    } else {
        while (temp->next != NULL) {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
    printf("\n");
}

int main()
{
    int a, b;
    printf("Enter the number of A: ");
    scanf("%d", &a);
    printf("Enter the number of B: ");
    scanf("%d", &b);

    data_node *head1 = NULL;
    head1 = createLL(head1, a);
    print_list(head1);

    data_node *head2 = NULL;
    head2 = createLL(head2, b);
    print_list(head2);

    head1 = reversal(head1);
    head2 = reversal(head2);

    print_list(head1);
    print_list(head2);

    return 0;
}
