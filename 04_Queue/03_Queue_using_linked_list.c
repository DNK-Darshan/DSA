#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue\n", value);
}

void dequeue() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("%d deleted from queue\n", front->data);

    front = front->next;

    if(front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue elements are:\n");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    enqueue(40);

    display();

    dequeue();
    dequeue();
    dequeue();

    dequeue();

    return 0;
}