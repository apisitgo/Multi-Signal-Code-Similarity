/*
   Programming Fundamentals - Lab exercise
   Task    : Algorithm #30 -- Divisors of a Number
   Student : <student id> <full name>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int divides(long d, long num)
{
    return !(num%d);
}

/* walk d from 1 up to num recursively */
static void print_from(long d, long num, int printedAny)
{
    if(d>num)
    {
        putchar('\n');
        return;
    }
    if(!divides(d,num))
    {
        print_from(d+1,num,printedAny);
        return;
    }
    printf(printedAny ? " %ld" : "%ld", d);
    print_from(d+1,num,1);
}

int main(void)
{
    long num;
    scanf("%ld",&num);
    print_from(1,num,0);
    return 0;
}
