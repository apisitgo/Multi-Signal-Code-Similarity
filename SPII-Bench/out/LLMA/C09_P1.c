#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for (int row = 1; row <= n; row++) {
        for (int sp = n - row; sp > 0; sp--) putchar(' ');
        for (int st = 0; st < 2 * row - 1; st++) putchar('*');
        putchar('\n');
    }
    return 0;
}
