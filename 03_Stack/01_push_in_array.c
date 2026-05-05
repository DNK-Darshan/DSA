#include <stdio.h>
#define MAX 4

int arr[MAX];
int top = -1;

void push(int data) {
    if(top == MAX - 1) {
        printf("The Stack is full\n");
        return;
    }
    top += 1;
    arr[top] = data;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    // push(5);

    for(int i = 0; i < MAX; i++) {
        printf(" %d", arr[i]);
    }
    return 0;
}
