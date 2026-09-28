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
        int count;
        scanf("%d", &count);

        long long total = 0;
        for (int k = 0; k < count; k++)
        {
                int val;
                scanf("%d", &val);
                total += val;       /* add each element */
        }

        printf("Sum = %lld\n", total);
        printf("Average = %.2f\n", (double)total / count);
        return 0;
}
