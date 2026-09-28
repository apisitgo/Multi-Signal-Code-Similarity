/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Basic Calculator #1 - Add Two Numbers
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long addNums(int p, int q)
{
    long total = p;
    total += q;
    return total;
}

int main(void)
{
    int firstNum, secondNum;
    long result;

    scanf("%d %d", &firstNum, &secondNum);

    result = addNums(firstNum, secondNum);
    printf("%ld\n", result);

    return 0;
}
