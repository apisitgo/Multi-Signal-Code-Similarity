/*
    Programming Fundamentals - Lab exercise
    Task    : Algorithm #23 - Binary Search
    Student : <student id> <full name>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_FOUND (-1)

static int *read_array(int size)
{
    int j = 0;
    int *arr = (int *)calloc(size > 0 ? size : 1, sizeof *arr);
    while (j < size)
        scanf("%d", arr + j++);
    return arr;
}

// standard binary search on a sorted array
static int bsearch_idx(const int *arr, int size, int key)
{
    int left = 0, right = size - 1, middle;
    int pos = NOT_FOUND;
    while (left <= right)
    {
        middle = left + right;
        middle /= 2;
        if (arr[middle] < key)
            left = middle + 1;
        else if (arr[middle] > key)
            right = middle - 1;
        else
        {
            pos = middle;
            break;
        }
    }
    return pos;
}

int main(void)
{
    int size, key, pos;
    int *arr;

    scanf("%d", &size);
    arr = read_array(size);
    scanf("%d", &key);

    pos = bsearch_idx(arr, size, key);
    free(arr);
    if (pos >= 0)
        printf("Found at index %d\n", pos);
    else
        puts("Not found");
    return 0;
}
