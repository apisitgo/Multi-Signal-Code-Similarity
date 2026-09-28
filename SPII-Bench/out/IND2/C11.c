/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #22 — Bubble Sort
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int numbers[1000];
    int i = 0;
    while (i < n) {
        scanf("%d", &numbers[i]);
        i = i + 1;
    }

    /* Bubble Sort */
    i = 0;
    while (i < n - 1) {
        int j = 0;
        while (j < n - 1 - i) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    i = 0;
    while (i < n) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", numbers[i]);
        i = i + 1;
    }
    printf("\n");

    return 0;
}
