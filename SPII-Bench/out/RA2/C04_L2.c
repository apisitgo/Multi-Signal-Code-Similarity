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
    int num;
    scanf("%d",&num);

    int isFirst=1;   /* no space before the first number */
    for(int d=1;d<=num;d++)
    {
        if(num%d==0)
        {
            if(!isFirst)
                printf(" ");
            printf("%d",d);
            isFirst=0;
        }
    }
    printf("\n");
    return 0;
}
