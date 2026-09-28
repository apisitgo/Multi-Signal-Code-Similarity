/*
    Programming Fundamentals - Lab exercise
    Task    : Algorithm #23 - Binary Search
    Student : <student id> <full name>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // read array
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int j = 0; j < size; j++)
        scanf("%d", &arr[j]);

    // read value to look for
    int key;
    scanf("%d", &key);

    // standard binary search on a sorted array
    int left = 0, right = size - 1, pos = -1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
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
    return 0;
}
