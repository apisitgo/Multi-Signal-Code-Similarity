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
    long long sum = 0;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        long long x;
        if (scanf("%lld", &x) != 1) break;
        sum += x;
    }
    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", n > 0 ? (double)sum / n : 0.0);
    return 0;
}
