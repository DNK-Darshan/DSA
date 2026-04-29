#include <stdio.h>

struct abc
{
    int a;
    int b;
};

void print(struct abc arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a: %d, b: %d\n", arr[i].a, arr[i].b);
    }
}

int main()
{
    struct abc arr[2] = {{1, 2}, {3, 4}};

    int n = sizeof(arr) / sizeof(arr[0]);

    // printf("%d", n);
    print(arr, n);

    return 0;
}