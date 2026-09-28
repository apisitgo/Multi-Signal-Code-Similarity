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
    int n, i, a;
    long long s = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        s += a;
    }
    printf("Sum = %lld\n", s);
    printf("Average = %.2f\n", (double)s / n);

    return 0;
}
