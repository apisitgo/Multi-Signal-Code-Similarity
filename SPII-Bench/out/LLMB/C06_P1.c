/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

int main(void)
{
    int count = 0;
    long long total = 0;

    if (scanf("%d", &count) != 1) return 0;
    for (int k = 0; k < count; k++) {
        int value;
        if (scanf("%d", &value) != 1) break;
        total += value;
    }

    double mean = (double) total / count;
    printf("Sum = %lld\n", total);
    printf("Average = %.2f\n", mean);
    return 0;
}
