/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Loops and Patterns #3 - Star Pyramid
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int rows;
    scanf("%d", &rows);

    for (int row = 1; row <= rows; row++) {
        // leading spaces then the stars for this row
        for (int sp = 0; sp < rows - row; sp++) printf(" ");
        for (int st = 0; st < 2 * row - 1; st++) printf("*");
        printf("\n");
    }

    return 0;
}
