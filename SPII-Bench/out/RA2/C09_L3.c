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
  int height, row, c;
  int spaces, stars;

  scanf("%d", &height);

  for (row = 1; row <= height; row++)
  {
    spaces = height - row;
    stars = 2*row - 1;
    // leading spaces
    for (c = 0; c < spaces; c++)
      printf(" ");
    // stars in this row
    for (c = 0; c < stars; c++)
      printf("*");
    printf("\n");
  }
  return 0;
}
