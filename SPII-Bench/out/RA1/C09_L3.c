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
    int starCount = 0;      // redundant counter

    scanf("%d", &rows);

    for (int row = 1; row <= rows; row++) {
        int spaces = rows - row;
        for (int sp = 0; sp < spaces; sp++) printf(" ");
        for (int st = 0; st < 2 * row - 1; st++) { printf("*"); starCount++; }
        printf("\n");
    }

    (void) starCount;
    return 0;
}
