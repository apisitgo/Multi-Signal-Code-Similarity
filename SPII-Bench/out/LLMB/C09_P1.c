/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static void repeat(char ch, int times)
{
    while (times-- > 0) putchar(ch);
}

int main(void)
{
    int rows;
    if (scanf("%d", &rows) != 1) return 0;
    for (int r = 1; r <= rows; r++) {
        repeat(' ', rows - r);
        repeat('*', 2 * r - 1);
        putchar('\n');
    }
    return 0;
}
