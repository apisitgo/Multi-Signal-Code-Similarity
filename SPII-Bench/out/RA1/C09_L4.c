/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Loops and Patterns #3 - Star Pyramid
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void printRow(int spaces, int stars)
{
    int starCount = 0;
    for (int sp = 0; sp < spaces; sp++) printf(" ");
    for (int st = 0; st < stars; st++) { printf("*"); starCount++; }
    (void) starCount;
    printf("\n");
}

int main(void)
{
    int rows;
    scanf("%d", &rows);

    for (int row = 1; row <= rows; row++) {
        printRow(rows - row, 2 * row - 1);
    }

    return 0;
}
