#include <stdio.h>

struct charset
{
    char s;
    int i;
};

void keyValue(char *s, int *i) {
    scanf("%c %d", s, i);
}

int main()
{
    struct charset s1;
    keyValue(&s1.s, &s1.i);
    printf("Character: %c\n", s1.s);
    printf("Integer: %d\n", s1.i);
    return 0;
}
