#include <stdio.h>

int main(void)
{
    /* find biggest of 3 numbers */
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int big = a;
    if (b > big) {
        big = b;
    }
    if (c > big) {
        big = c;
    }

    printf("%d\n", big);
    return 0;
}
