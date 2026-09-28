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
        int k = count;
        long val;
        long long total = 0;
        while (k-- > 0)
        {
                scanf("%ld", &val);
                total = total + val;
        }
        return total;
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
