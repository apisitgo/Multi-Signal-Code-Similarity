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

static void swap_int(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/* bubble sort: after pass p the largest p+1 items are at the end */
static void bubble(int *arr, int len)
{
    int p, q, lastIdx = len - 1;
    for (p = 0; p < lastIdx; p++)
        for (q = 0; q < lastIdx - p; q++)
            if (arr[q] > arr[q + 1])
                swap_int(&arr[q], &arr[q + 1]);
}

static void print_all(const int *arr, int len)
{
    int p;
    for (p = 0; p < len; p++)
    {
        printf("%d", arr[p]);
        if (p < len - 1)
            printf(" ");
    }
    printf("\n");
}

int main(void)
{
    int len, p;

    scanf("%d", &len);
    for (p = 0; p < len; p++)
        scanf("%d", &nums[p]);

    bubble(nums, len);
    print_all(nums, len);
    return 0;
}
