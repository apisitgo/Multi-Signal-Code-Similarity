#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    long long x = 0, y = 1;
    for (int k = 0; k < n; k++) {
        printf("%lld", x);
        if (k < n - 1) printf(" ");
        long long nxt = x + y;
        x = y;
        y = nxt;
    }
    printf("\n");
    return 0;
}
