/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #1 — Add Two Numbers
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a, b;

    // Read two numbers
    scanf("%d", &a);
    scanf("%d", &b);

    // Calculate sum
    int sum = a + b;

    printf("%d\n", sum);

    return 0;
}
