/*
 *  Programming Fundamentals - Lab exercise
 *  Task    : Algorithm #22 - Bubble Sort
 *  Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000

int nums[MAXN];

int main(void)
{
    int len, p, q, tmp, lastIdx;

    scanf("%d", &len);
    lastIdx = len - 1;

    for (p = 0; p < len; p++)
        scanf("%d", &nums[p]);

    /* bubble sort: after pass p the largest p+1 items are at the end */
    for (p = 0; p < lastIdx; p++)
    {
        for (q = 0; q < lastIdx - p; q++)
        {
            if (nums[q] > nums[q + 1])
            {
                tmp = nums[q];
                nums[q] = nums[q + 1];
                nums[q + 1] = tmp;
            }
        }
    }

    /* print space separated */
    for (p = 0; p < len; p++)
    {
        printf("%d", nums[p]);
        if (p < lastIdx)
            printf(" ");
    }
    printf("\n");
    return 0;
}
