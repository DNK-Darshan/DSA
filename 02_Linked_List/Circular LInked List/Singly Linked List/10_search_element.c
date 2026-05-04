#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *addNode(int data) {
    data_node *temp = (data_node *)malloc(sizeof(data_node));
    temp->data = data;
    temp->next = temp;

    return temp;
}

data_node *add_at_first(data_node *tail, int data) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = data;
    ptr->next = tail->next;
    tail->next = ptr;

    return tail;
}

data_node *add_at_end(data_node *tail, int data) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;

    return tail;
}

void print_list(data_node *tail) {
    data_node *ptr = tail->next;
    do {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
}

int search_list(data_node *tail, int ele) {
    data_node *temp = tail->next;
    int index = 0;
    if(tail == NULL) {
        return -2;
    }

    do{
        if(temp->data == ele) {
            return index;
        }
        temp = temp->next;
        index++;
    } while(temp != tail->next);

    return -1;
}

int main()
{
    data_node *tail = NULL;
    int ele;
    tail = addNode(14);
    tail = add_at_first(tail, 11);
    tail = add_at_first(tail, 24);
    tail = add_at_end(tail, 16);
    tail = add_at_end(tail, 17);

    print_list(tail);

    printf("\nEnter the element you want to find: ");
    scanf("%d", &ele);

    int index = search_list(tail, ele);

    if(index == -2) {
        printf("\nLinked list is empty\n");
    } else if(index == -1) {
        printf("\nElement is not found\n");
    } else {
        printf("\nElement %d is at index %d\n", ele, index);
    }

    return 0;
}
