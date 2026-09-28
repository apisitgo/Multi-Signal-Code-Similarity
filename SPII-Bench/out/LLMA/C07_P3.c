#include <stdio.h>

int main(void)
{
    /* print fibonacci series */
    int n;
    scanf("%d", &n);

    long long f1 = 0;
    long long f2 = 1;

    for (int i = 0; i < n; i++) {
        printf("%lld", f1);
        if (i < n - 1) {
            printf(" ");
        }
        long long f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    printf("\n");
    return 0;
}
