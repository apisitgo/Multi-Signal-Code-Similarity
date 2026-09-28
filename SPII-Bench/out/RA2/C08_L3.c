/*
    Programming Fundamentals - Lab exercise
    Task    : Algorithm #23 - Binary Search
    Student : <student id> <full name>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_FOUND (-1)

int main(void)
{
    int size, key, j;
    int left, right, middle;
    int pos = NOT_FOUND;
    int *arr;

    // read array
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * (size > 0 ? size : 1));
    for (j = 0; j < size; j++)
        scanf("%d", &arr[j]);

    // read value to look for
    scanf("%d", &key);

    // standard binary search on a sorted array
    left = 0;
    right = size - 1;
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

    if (pos >= 0)
        printf("Found at index %d\n", pos);
    else
        printf("Not found\n");
    free(arr);
    return 0;
}
