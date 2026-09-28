#include <stdio.h>
#include <stdlib.h>

static long long accumulate_sum(int count)
{
    long long accumulator = 0;
    for (int index = 0; index < count; index++) {
        int element;
        scanf("%d", &element);
        accumulator += element;
    }
    return accumulator;
}

int main(void)
{
    int element_count;
    scanf("%d", &element_count);

    long long sum_value = accumulate_sum(element_count);
    double average_value = (double) sum_value / element_count;

    printf("Sum = %lld\n", sum_value);
    printf("Average = %.2f\n", average_value);

    return 0;
}
