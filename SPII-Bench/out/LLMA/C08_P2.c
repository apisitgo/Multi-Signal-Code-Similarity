#include <stdio.h>
#include <stdlib.h>

static int binary_search_index(const int *array, int length, int target_value)
{
    int low_bound = 0;
    int high_bound = length - 1;

    while (low_bound <= high_bound) {
        int middle_position = (low_bound + high_bound) / 2;
        if (array[middle_position] == target_value) {
            return middle_position;
        } else if (array[middle_position] < target_value) {
            low_bound = middle_position + 1;
        } else {
            high_bound = middle_position - 1;
        }
    }
    return -1;
}

int main(void)
{
    int size;
    scanf("%d", &size);

    int values[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &values[i]);
    }

    int search_target;
    scanf("%d", &search_target);

    int position = binary_search_index(values, size, search_target);

    if (position >= 0) {
        printf("Found at index %d\n", position);
    } else {
        printf("Not found\n");
    }

    return 0;
}
