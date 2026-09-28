#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    long long total = 0;
    for (int k = 0; k < n; k++) {
        int v;
        scanf("%d", &v);
        total += v;
    }
    printf("Sum = %lld\n", total);
    printf("Average = %.2f\n", (double) total / n);
    return 0;
}
