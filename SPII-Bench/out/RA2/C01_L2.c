/*
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #12 - Largest of Three
 * Student: <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* return the bigger one of two ints */
static int bigger( int p, int q ) {
  return p > q ? p : q;
}

int main(void) {
  int n1, n2, n3;

  /* read the three numbers */
  scanf( "%d %d %d", &n1, &n2, &n3 );
  printf( "%d\n", bigger( n1, bigger( n2, n3 ) ) );
  return 0;
}
