/*
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #12 - Largest of Three
 * Student: <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* largest of three values in one go */
static long biggest_of3( long p, long q, long r ) {
  long m = q > r ? q : r;
  return p > m ? p : m;
}

static void show( long v ) {
  printf( "%ld\n", v );
}

int main(void) {
  int n1;
  int n2;
  int n3;
  long answer;

  /* read the three numbers */
  scanf( "%d %d %d", &n1, &n2, &n3 );
  answer = biggest_of3( n1, n2, n3 );
  show( answer );
  return 0;
}
