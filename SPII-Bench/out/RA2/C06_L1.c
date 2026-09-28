/*
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #14 -- Sum and Average of Array
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
        int n;
        scanf("%d", &n);

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
                int x;
                scanf("%d", &x);
                sum += x;       /* add each element */
        }

        printf("Sum = %lld\n", sum);
        printf("Average = %.2f\n", (double)sum / n);
        return 0;
}
