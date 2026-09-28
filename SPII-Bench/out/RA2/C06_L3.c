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
        int count, k;
        long val;
        long long total;
        double avg;

        scanf("%d", &count);
        total = 0;
        for (k = 0; k < count; k++)
        {
                scanf("%ld", &val);
                total += val;       /* add each element */
        }

        avg = (double)total / count;
        printf("Sum = %lld\n", total);
        printf("Average = %.2f\n", avg);
        return 0;
}
