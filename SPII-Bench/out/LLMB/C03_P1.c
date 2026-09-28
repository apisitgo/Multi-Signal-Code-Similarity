/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static int add(int x, int y)
{
    return x + y;
}

int main(void)
{
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);
    printf("%d\n", add(x, y));
    return 0;
}
