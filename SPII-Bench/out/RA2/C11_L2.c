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
    int len;
    scanf("%d", &len);

    int nums[len];
    for (int p = 0; p < len; p++)
        scanf("%d", &nums[p]);

    /* bubble sort: after pass p the largest p+1 items are at the end */
    for (int p = 0; p < len - 1; p++)
    {
        for (int q = 0; q < len - 1 - p; q++)
        {
            if (nums[q] > nums[q + 1])
            {
                int tmp = nums[q];
                nums[q] = nums[q + 1];
                nums[q + 1] = tmp;
            }
        }
    }

    /* print space separated */
    for (int p = 0; p < len; p++)
    {
        printf("%d", nums[p]);
        if (p < len - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
