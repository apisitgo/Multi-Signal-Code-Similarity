#include <stdio.h>

int main(void)
{
    /* sum and average of array */
    int n;
    scanf("%d", &n);

    long long sum = 0;
    int i = 0;
    while (i < n) {
        int x;
        scanf("%d", &x);
        sum = sum + x;
        i = i + 1;
    }

    double avg = (double) sum / (double) n;

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", avg);
    return 0;
}
