/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Loops and Patterns #3 — Star Pyramid
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    printf("Enter height: ");
    scanf("%d", &n);

    int i = 1;
    while (i <= n) {
        int spaces = n - i;
        int stars = 2 * i - 1;

        int j = 0;
        while (j < spaces) {
            printf(" ");
            j = j + 1;
        }

        j = 0;
        while (j < stars) {
            printf("*");
            j = j + 1;
        }

        printf("\n");
        i = i + 1;
    }

    return 0;
}
