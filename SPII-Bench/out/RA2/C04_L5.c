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

static void print_divisors(long num)
{
    long d=1;
    const char *sep="";   /* nothing before the first number */
    while(d<=num)
    {
        if(divides(d,num))
        {
            printf("%s%ld",sep,d);
            sep=" ";
        }
        d=d+1;
    }
    putchar('\n');
}

int main(void)
{
    long num;
    scanf("%ld",&num);
    print_divisors(num);
    return 0;
}
