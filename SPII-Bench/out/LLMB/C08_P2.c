/* Binary search over a sorted array read from stdin. */
#include <stdio.h>
#include <stdlib.h>

static int bsearch_index(const int *arr, int size, int key)
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
    int size, k, key;
    scanf("%d", &size);
    int *arr = malloc(sizeof(int) * (size > 0 ? size : 1));
    for (k = 0; k < size; k++)
        scanf("%d", &arr[k]);
    scanf("%d", &key);

    int where = bsearch_index(arr, size, key);
    if (where < 0)
        puts("Not found");
    else
        printf("Found at index %d\n", where);

    free(arr);
    return 0;
}
