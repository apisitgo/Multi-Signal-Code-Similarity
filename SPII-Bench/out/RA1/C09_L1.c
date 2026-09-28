/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Loops and Patterns #3 - Star Pyramid
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // leading spaces then the stars for this row
        for (int s = 0; s < n - i; s++) printf(" ");
        for (int s = 0; s < 2 * i - 1; s++) printf("*");
        printf("\n");
    }

    return 0;
}
