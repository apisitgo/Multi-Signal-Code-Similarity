// sum and average of n numbers
#include <stdio.h>

int main(void)
{
    int n, i;
    int nums[1000];
    long long sum = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (i = 0; i < n; i++) {
        sum = sum + nums[i];
    }

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", sum * 1.0 / n);
    return 0;
}
