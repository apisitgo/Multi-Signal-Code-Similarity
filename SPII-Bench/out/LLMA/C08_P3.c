#include <stdio.h>

int main(void)
{
    /* binary search */
    int n;
    scanf("%d", &n);
    int arr[100];
    int i = 0;
    while (i < n) {
        scanf("%d", &arr[i]);
        i = i + 1;
    }

    int target;
    scanf("%d", &target);

    int lo = 0;
    int hi = n - 1;
    int found_idx = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) {
            found_idx = mid;
            break;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    if (found_idx != -1) {
        printf("Found at index %d\n", found_idx);
    } else {
        printf("Not found\n");
    }

    return 0;
}
