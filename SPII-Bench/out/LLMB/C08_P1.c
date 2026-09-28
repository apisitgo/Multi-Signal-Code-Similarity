/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static int binary_search(const int *arr, int size, int key)
{
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main(void)
{
    int size;
    if (scanf("%d", &size) != 1) return 0;
    int arr[size];
    for (int k = 0; k < size; k++) scanf("%d", &arr[k]);
    int key;
    scanf("%d", &key);

    int pos = binary_search(arr, size, key);
    if (pos < 0)
        printf("Not found\n");
    else
        printf("Found at index %d\n", pos);
    return 0;
}
