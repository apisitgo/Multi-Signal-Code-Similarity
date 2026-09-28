// ------------------------------------------------------------
// Programming Fundamentals - Lab exercise
// Task    : Loops and Patterns #3 - Star Pyramid
// Student : <student id> <full name>
// ------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int height;
  scanf("%d", &height);

  for (int row = 1; row <= height; row++)
  {
    // leading spaces
    for (int c = 0; c < height - row; c++)
      printf(" ");
    // stars in this row
    for (int c = 0; c < 2*row - 1; c++)
      printf("*");
    printf("\n");
  }
  return 0;
}
