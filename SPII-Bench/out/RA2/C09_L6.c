// ------------------------------------------------------------
// Programming Fundamentals - Lab exercise
// Task    : Loops and Patterns #3 - Star Pyramid
// Student : <student id> <full name>
// ------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print `times` copies of the same character (recursive)
static void repeat(char ch, int times)
{
  if (times <= 0)
    return;
  putchar(ch);
  repeat(ch, times - 1);
}

static void draw_row(int row, int height)
{
  repeat(' ', height - row);
  repeat('*', row + row - 1);
  putchar('\n');
}

int main(void)
{
  int height, row = 0;

  scanf("%d", &height);
  for (;;)
  {
    row++;
    if (row > height)
      break;
    draw_row(row, height);
  }
  return 0;
}
