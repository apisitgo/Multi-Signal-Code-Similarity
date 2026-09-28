// fibonacci sequence, first n terms
#include <stdio.h>

int main(void)
{
    int n, i;
    long long fib[100];

    scanf("%d", &n);

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (i = 0; i < n; i++) {
        printf("%lld", fib[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
