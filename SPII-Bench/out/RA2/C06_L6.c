/*
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #14 -- Sum and Average of Array
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* sum the next `left` numbers recursively */
static long long read_and_sum(int left)
{
        long val;
        if (left <= 0)
                return 0;
        scanf("%ld", &val);
        return val + read_and_sum(left - 1);
}

static void report(long long total, int count)
{
        printf("Sum = %lld\nAverage = %.2f\n", total, (double)total / count);
}

int main(void)
{
        int count;
        scanf("%d", &count);
        report(read_and_sum(count), count);
        return 0;
}
