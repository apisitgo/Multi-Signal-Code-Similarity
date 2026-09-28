/*
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #12 - Largest of Three
 * Student: <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* return the bigger one of two ints */
static int max2( int x, int y ) {
  return x > y ? x : y;
}

int main(void) {
  int a, b, c;

  /* read the three numbers */
  scanf( "%d %d %d", &a, &b, &c );
  printf( "%d\n", max2( a, max2( b, c ) ) );
  return 0;
}
