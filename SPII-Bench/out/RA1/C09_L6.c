/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Loops and Patterns #3 - Star Pyramid
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void printRow(int spaces, int stars)
{
    int sp = 0;
    while (sp < spaces) { printf(" "); sp++; }
    int st = 0;
    while (st < stars) { printf("*"); st++; }
    printf("\n");
}

/* recursion instead of the outer loop */
static void printRowsFrom(int row, int rows)
{
    if (row > rows) return;
    printRow(rows - row, 2 * row - 1);
    printRowsFrom(row + 1, rows);
}

int main(void)
{
    int rows;
    scanf("%d", &rows);

    printRowsFrom(1, rows);

    return 0;
}
