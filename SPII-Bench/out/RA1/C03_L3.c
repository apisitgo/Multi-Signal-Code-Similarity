/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Basic Calculator #1 - Add Two Numbers
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int firstNum, secondNum;
    long total = 0;

    scanf("%d", &firstNum);
    scanf("%d", &secondNum);

    total = firstNum + secondNum;
    // sum of the two inputs
    printf("%ld\n", total);

    return 0;
}
