#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insertFront(int value) {
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    printf("%d inserted at front\n", value);
}

void insertRear(int value) {
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }

    printf("%d inserted at rear\n", value);
}

void deleteFront() {
    struct node *temp;

    if(front == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    temp = front;

    printf("%d deleted from front\n", front->data);

    front = front->next;

    if(front != NULL)
    {
        front->prev = NULL;
    }
    else
    {
        rear = NULL;
    }

    free(temp);
}

void deleteRear() {
    struct node *temp;

    if(rear == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    temp = rear;

    printf("%d deleted from rear\n", rear->data);

    rear = rear->prev;

    if(rear != NULL)
    {
        rear->next = NULL;
    }
    else
    {
        front = NULL;
    }

    free(temp);
}

void display() {
    struct node *temp;

    if(front == NULL)
    {
        printf("Deque is empty\n");
        return;
    }

    temp = front;

    printf("Deque elements are:\n");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    insertFront(10);
    insertFront(20);

    insertRear(30);
    insertRear(40);

    display();

    deleteFront();

    display();

    deleteRear();

    display();

    return 0;
}