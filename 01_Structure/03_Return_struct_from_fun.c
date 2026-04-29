#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point edit(struct point p) {
    p.x++;
    p.y += 5;
    return p;
}

void print(struct point p) {
    printf("\nX: %d", p.x);
    printf("\nY: %d\n", p.y);
}

int main()
{
    struct point p1 = {23, 45};
    struct point p2 = {78, 90};

    p1 = edit(p1);
    print(p1);
    print(p2);

    return 0;
}
