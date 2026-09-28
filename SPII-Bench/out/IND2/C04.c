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
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int i = 1;
    int first = 1;
    while (i <= n) {
        if (n % i == 0) {
            if (!first) {
                printf(" ");
            }
            printf("%d", i);
            first = 0;
        }
        i = i + 1;
    }
    printf("\n");

    return 0;
}
