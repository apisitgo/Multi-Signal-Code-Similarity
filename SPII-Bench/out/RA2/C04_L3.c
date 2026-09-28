/*
   Programming Fundamentals - Lab exercise
   Task    : Algorithm #30 -- Divisors of a Number
   Student : <student id> <full name>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long num, d;
    int isFirst, count = 0;

    scanf("%ld",&num);

    isFirst=1;   /* no space before the first number */
    for(d=1;d<=num;d++)
    {
        if(num%d==0)
        {
            if(!isFirst)
                printf(" ");
            printf("%ld",d);
            isFirst=0;
            count++;
        }
    }
    printf("\n");
    return 0;
}
