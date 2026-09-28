#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int k = 0; k < n; k++) scanf("%d", &a[k]);

    for (int pass = 0; pass < n - 1; pass++) {
        for (int j = 0; j < n - 1 - pass; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        printf("%d", a[k]);
        if (k < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
