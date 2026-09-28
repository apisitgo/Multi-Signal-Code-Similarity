/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Basic Calculator #1 - Add Two Numbers
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int firstNum;
    int secondNum;

    scanf("%d", &firstNum);
    scanf("%d", &secondNum);

    // sum of the two inputs
    printf("%d\n", firstNum + secondNum);

    return 0;
}
