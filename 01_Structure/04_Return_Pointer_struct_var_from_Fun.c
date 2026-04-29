#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

struct point *fun(int a, int b) {
    struct point *ptr = (struct point *)malloc(sizeof(struct point));
    ptr->x = a;
    ptr->y = b + 5;
    return ptr;
}

void print(struct point *ptr) {
    printf("\nX: %d", ptr->x);
    printf("\nY: %d\n", ptr->y);
}

int main()
{
    struct point *ptr1, *ptr2;

    ptr1 = fun(2, 3);
    print(ptr1);

    ptr2 = (struct point *)malloc(sizeof(struct point));
    ptr2->x = 78;
    ptr2->y = 90;
    print(ptr2);

    return 0;
}
