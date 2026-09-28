/*
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #14 -- Sum and Average of Array
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* read `count` numbers and return their sum */
static long long read_and_sum(int count)
{
        int k;
        long val;
        long long total = 0;
        for (k = 0; k < count; k++)
        {
                scanf("%ld", &val);
                total += val;
        }
        return total;
}

static void report(long long total, int count)
{
        double avg = (double)total / count;
        printf("Sum = %lld\n", total);
        printf("Average = %.2f\n", avg);
}

int main(void)
{
        int count;
        scanf("%d", &count);
        report(read_and_sum(count), count);
        return 0;
}
