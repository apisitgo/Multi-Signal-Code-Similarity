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
  int c;
  for (c = 0; c < times; c++)
    printf("%c", ch);
}

static void draw_row(int row, int height)
{
  repeat(' ', height - row);
  repeat('*', 2*row - 1);
  printf("\n");
}

int main(void)
{
  int height, row;

  scanf("%d", &height);
  for (row = 1; row <= height; row++)
    draw_row(row, height);
  return 0;
}
