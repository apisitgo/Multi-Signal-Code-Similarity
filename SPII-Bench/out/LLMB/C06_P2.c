/* Sum and mean of a sequence of integers. */
#include <stdio.h>

int main(void)
{
    int count = 0, k, value;
    long long accum = 0;

    scanf("%d", &count);
    k = count;
    while (k-- > 0) {
        scanf("%d", &value);
        accum += value;
    }

    double mean = (double) accum / count;
    printf("Sum = %lld\n", accum);
    printf("Average = %.2f\n", mean);
    return 0;
}
