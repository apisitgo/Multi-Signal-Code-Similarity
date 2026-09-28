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
    return num%d==0;
}

static void print_divisors(long num)
{
    long d;
    int isFirst=1;   /* no space before the first number */
    for(d=1;d<=num;d++)
    {
        if(divides(d,num))
        {
            if(!isFirst)
                printf(" ");
            printf("%ld",d);
            isFirst=0;
        }
    }
    printf("\n");
}

int main(void)
{
    long num;
    scanf("%ld",&num);
    print_divisors(num);
    return 0;
}
