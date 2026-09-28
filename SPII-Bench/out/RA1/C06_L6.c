/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #14 - Sum and Average of Array
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long readAndSum(int count)
{
    long long total = 0;
    int idx = 0;
    for (;;) {
        if (idx >= count) break;
        int val;
        scanf("%d", &val);
        total = total + val;
        idx++;
    }
    return total;
}

int main(void)
{
    int count;
    long long total;
    double avg;

    scanf("%d", &count);
    total = readAndSum(count);
    avg = (double) total / count;

    printf("Sum = %lld\n", total);
    printf("Average = %.2f\n", avg);

    return 0;
}
