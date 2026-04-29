#include <stdio.h>

struct abc
{
    int i;
    char c;
    struct abc *ptr; // Self-referential structure
};

int main()
{
    struct abc s1;
    struct abc s2;

    s1.i = 10;
    s1.c = 'A';
    s1.ptr = NULL;

    s2.i = 20;
    s2.c = 'B';
    s2.ptr = &s1;

    printf("s2.i: %d\n", s2.i);
    printf("s2.c: %c\n", s2.c);
    printf("s2.ptr: %d %c\n", s2.ptr->i, s2.ptr->c);

    return 0;
}
