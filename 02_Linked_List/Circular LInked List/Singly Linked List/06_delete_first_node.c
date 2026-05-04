#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} data_node;

data_node *add_at_end(data_node *tail, int data) {
    data_node *ptr = (data_node *)malloc(sizeof(data_node));
    ptr->data = data;
    ptr->next = NULL;

    if(tail == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;

    return tail;
}

data_node *create_list(data_node *tail) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n == 0) {
        return tail;
    }

    for(int i = 1; i <= n; i++) {
        printf("Enter the data of %d node: ", i);
        scanf("%d", &data);
        tail = add_at_end(tail, data);
    }

    return tail;
}

data_node *delete_first(data_node *tail) {
    if(tail == NULL) {
        return tail;
    }
    if(tail->next == tail) {
        free(tail);
        tail = NULL;
        return tail;
    }
    data_node *ptr = tail->next;
    tail->next = ptr->next;
    free(ptr);
    ptr = NULL;

    return tail;
}

void print_list(data_node *tail) {
    if(tail == NULL) {
        printf("\nThe List is empty");
    } else {
        data_node *ptr = tail->next;
        do {
            printf(" %d", ptr->data);
            ptr = ptr->next;
        } while(ptr != tail->next);
    }
    printf("\n");
}

int main()
{
    data_node *tail = NULL;
    tail = create_list(tail);
    print_list(tail);

    tail = delete_first(tail);
    print_list(tail);

    return 0;
}
