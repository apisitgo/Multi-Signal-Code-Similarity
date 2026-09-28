/* Centered star pyramid of n rows. */
#include <stdio.h>

static void repeat(char ch, int times)
{
    while (times-- > 0)
        putchar(ch);
}

int main(void)
{
    int rows, r;
    scanf("%d", &rows);
    for (r = 1; r <= rows; r++) {
        repeat(' ', rows - r);
        repeat('*', 2 * r - 1);
        putchar('\n');
    }
    return 0;
}
