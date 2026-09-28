/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Basic Calculator #1 - Add Two Numbers
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long addNums(int p, int q)
{
    long total = 0;
    total = p + q;
    return total;
}

int main(void)
{
    int firstNum, secondNum;

    scanf("%d", &firstNum);
    scanf("%d", &secondNum);

    printf("%ld\n", addNums(firstNum, secondNum));

    return 0;
}
