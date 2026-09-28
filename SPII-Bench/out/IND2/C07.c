/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 — Fibonacci Series
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    long long prev = 0;
    long long curr = 1;

    int i = 0;
    while (i < n) {
        if (i > 0) {
            printf(" ");
        }
        printf("%lld", prev);

        long long next = prev + curr;
        prev = curr;
        curr = next;

        i = i + 1;
    }
    printf("\n");

    return 0;
}
