#include <stdio.h>

int main(void)
{
    /* bubble sort */
    int n;
    scanf("%d", &n);
    int arr[100];
    int i = 0;
    while (i < n) {
        scanf("%d", &arr[i]);
        i = i + 1;
    }

    int a = 0;
    while (a < n - 1) {
        int b = 0;
        while (b < n - 1 - a) {
            if (arr[b] > arr[b + 1]) {
                int t = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = t;
            }
            b = b + 1;
        }
        a = a + 1;
    }

    i = 0;
    while (i < n) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
        i = i + 1;
    }
    printf("\n");
    return 0;
}
