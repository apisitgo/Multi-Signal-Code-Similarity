#include <stdio.h>

static int larger(int p, int q) {
    return (p > q) ? p : q;
}

int main(void) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int best = larger(larger(x, y), z);
    printf("%d\n", best);
    return 0;
}
