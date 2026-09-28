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
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

/* bubble sort: after each pass the largest remaining item is at `end` */
static void bubble(int *arr, int len)
{
    int end = len - 1;
    while (end > 0)
    {
        int q = 0;
        while (q < end)
        {
            if (arr[q + 1] < arr[q])
                swap_int(arr + q, arr + q + 1);
            q++;
        }
        end = end - 1;
    }
}

static void print_all(const int *arr, int len)
{
    int p;
    for (p = 0; p < len; p++)
        printf(p ? " %d" : "%d", arr[p]);
    putchar('\n');
}

int main(void)
{
    int len, p = 0;

    scanf("%d", &len);
    while (p < len)
        scanf("%d", nums + p++);

    bubble(nums, len);
    print_all(nums, len);
    return 0;
}
