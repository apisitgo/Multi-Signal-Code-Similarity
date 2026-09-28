/*
 *  Programming Fundamentals - Lab exercise
 *  Task    : Algorithm #22 - Bubble Sort
 *  Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    /* bubble sort: after pass i the largest i+1 items are at the end */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    /* print space separated */
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
