// sort numbers in ascending order (selection sort)
#include <stdio.h>

int main(void)
{
    int n, i, j, min, temp;
    int arr[1000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}
