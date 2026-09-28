/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Basic Calculator #1 - Add Two Numbers
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a;
    int b;

    scanf("%d", &a);
    scanf("%d", &b);

    // sum of the two inputs
    printf("%d\n", a + b);

    return 0;
}
