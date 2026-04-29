#include <stdio.h>

int add_at_first(int a[], int n, int data) {
    for(int i = n - 1; i >= 0; i--) {
        a[i + 1] = a[i];
    }
    a[0] = data;
    return n + 1;
}

int main()
{
    int a[10], n, data = 10;

    printf("Enter n: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter A[%d]: ", i);
        scanf("%d", &a[i]);
    }

    n = add_at_first(a, n, data);

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
