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
    scanf("%d", &count);

    long long total = 0;
    for (int idx = 0; idx < count; idx++) {
        int val;
        scanf("%d", &val);
        total += val;
    }

    printf("Sum = %lld\n", total);
    printf("Average = %.2f\n", (double) total / count);

    return 0;
}
