/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #22 — Bubble Sort
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bsort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int sw = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                sw = 1;
            }
        }
        if (!sw) break;
    }
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) return 0;
    int *a = malloc(sizeof(int) * (n > 0 ? n : 1));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    bsort(a, n);
    for (int i = 0; i < n; i++) printf(i ? " %d" : "%d", a[i]);
    printf("\n");
    free(a);
    return 0;
}
