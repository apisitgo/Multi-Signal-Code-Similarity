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
    int j;
    int *arr = (int *)malloc(sizeof(int) * (size > 0 ? size : 1));
    for (j = 0; j < size; j++)
        scanf("%d", &arr[j]);
    return arr;
}

// standard binary search on a sorted array
static int bsearch_idx(const int *arr, int size, int key)
{
    int left = 0, right = size - 1, middle;
    int pos = NOT_FOUND;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (arr[middle] == key)
        {
            pos = middle;
            break;
        }
        else if (arr[middle] < key)
            left = middle + 1;
        else
            right = middle - 1;
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
    if (pos >= 0)
        printf("Found at index %d\n", pos);
    else
        printf("Not found\n");
    free(arr);
    return 0;
}
