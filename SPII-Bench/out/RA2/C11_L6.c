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

/* one pass over arr[0..end], then recurse on the shorter prefix */
static void bubble(int *arr, int end)
{
    int q;
    if (end <= 0)
        return;
    for (q = 0; q < end; q++)
    {
        if (!(arr[q + 1] < arr[q]))
            continue;
        swap_int(arr + q, arr + q + 1);
    }
    bubble(arr, end - 1);
}

static void print_all(const int *arr, int len)
{
    int p;
    for (p = 0; p < len; p++)
    {
        if (p != 0)
            putchar(' ');
        printf("%d", arr[p]);
    }
    putchar('\n');
}

int main(void)
{
    int len, p = 0;

    scanf("%d", &len);
    while (p < len)
        scanf("%d", nums + p++);

    bubble(nums, len - 1);
    print_all(nums, len);
    return 0;
}
