// ------------------------------------------------------------
// Programming Fundamentals - Lab exercise
// Task    : Loops and Patterns #3 - Star Pyramid
// Student : <student id> <full name>
// ------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print `times` copies of the same character
static void repeat(char ch, int times)
{
  while (times-- > 0)
    putchar(ch);
}

static void draw_row(int row, int height)
{
  repeat(' ', height - row);
  repeat('*', row + row - 1);
  putchar('\n');
}

int main(void)
{
  int height, row = 1;

  scanf("%d", &height);
  while (row <= height)
  {
    draw_row(row, height);
    row = row + 1;
  }
  return 0;
}
