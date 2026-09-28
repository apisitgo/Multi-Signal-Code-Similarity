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
    scanf("%d", &n);

    if (n >= 1) {
        printf("0");
    }

    if (n >= 2) {
        printf(" 1");
    }

    // Generate Fibonacci series
    int prev = 0;
    int curr = 1;
    for (int i = 2; i < n; i++) {
        int next = prev + curr;
        printf(" %d", next);
        prev = curr;
        curr = next;
    }

    printf("\n");

    return 0;
}
