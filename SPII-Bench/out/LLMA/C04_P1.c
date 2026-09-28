#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int printed = 0;
    for (int d = 1; d <= n; d++) {
        if (n % d != 0) continue;
        if (printed) printf(" ");
        printf("%d", d);
        printed = 1;
    }
    printf("\n");
    return 0;
}
