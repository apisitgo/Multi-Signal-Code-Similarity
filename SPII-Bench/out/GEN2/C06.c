/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #14 — Sum and Average of Array
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        if (scanf("%lld", &x) != 1) return 1;
        sum += x;
    }
    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", (double)sum / n);

    return 0;
}
