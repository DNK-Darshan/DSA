#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue {
    int size;
    int f;
    int r;
    int *arr;
} queue;

int isFull(queue *q) {
    if((q->r+1) % q->size == q->f) {
        return 1;
    }
    return 0;
}

int isEmpty(queue *q) {
    if(q->r == q->f) {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int val) {
    if(isFull(q)) {
        printf("This queue is full\n");
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("%d is add in queue\n", val);
    }
}

int dequeue(queue *q) {
    int a = -1;
    if(isEmpty(q)) {
        printf("This queue is Empty\n");
    } else {
        q->f = (q->f  + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    queue q;
    q.size = 4;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue some elements
    enqueue(&q, 11);
    enqueue(&q, 14);
    enqueue(&q, 11);
    enqueue(&q, 31);
    enqueue(&q, 11);

    // printf("Dequeue elements is %d\n", dequeue(&q));
    // printf("Dequeue elements is %d\n", dequeue(&q));
    
    if(isEmpty(&q)) {
        printf("This queue is Empty\n");
    }

    if(isFull(&q)) {
        printf("This queue is Full\n");
    }

    return 0;
}
