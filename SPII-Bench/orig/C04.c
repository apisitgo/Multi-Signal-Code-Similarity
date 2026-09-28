/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #30 — Divisors of a Number
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int first = 1;
    for (int i = 1; i <= n; i++)
        if (n % i == 0) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    printf("\n");

    return 0;
}
