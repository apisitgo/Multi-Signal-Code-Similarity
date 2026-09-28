/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #14 - Sum and Average of Array
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int count;
    long long total;
    double avg;

    scanf("%d", &count);
    total = 0;

    for (int idx = 0; idx < count; idx++) {
        int val;
        scanf("%d", &val);
        total += val;
    }

    avg = (double) total / count;
    printf("Sum = %lld\n", total);
    printf("Average = %.2f\n", avg);

    return 0;
}
