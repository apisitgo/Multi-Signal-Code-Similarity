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

// recursive binary search on arr[left..right]
static int bsearch_idx(const int *arr, int left, int right, int key)
{
    int middle;
    if (left > right)
        return NOT_FOUND;
    middle = left + right;
    middle /= 2;
    if (arr[middle] == key)
        return middle;
    if (arr[middle] < key)
        return bsearch_idx(arr, middle + 1, right, key);
    return bsearch_idx(arr, left, middle - 1, key);
}

int main(void)
{
    int size, key, pos;
    int *arr;

    scanf("%d", &size);
    arr = read_array(size);
    scanf("%d", &key);

    pos = bsearch_idx(arr, 0, size - 1, key);
    free(arr);
    if (pos < 0) {
        puts("Not found");
        return 0;
    }
    printf("Found at index %d\n", pos);
    return 0;
}
