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

int main(void)
{
    int rows;
    scanf("%d", &rows);

    int row = 1;
    while (row <= rows) {
        printRow(rows - row, 2 * row - 1);
        row++;
    }

    return 0;
}
