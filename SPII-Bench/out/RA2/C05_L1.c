/* ============================================================
   Programming Fundamentals - Lab exercise
   Task    : Algorithm #8 -- LCM (Least Common Multiple)
   Student : <student id> <full name>
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  long long a, b;
  scanf("%lld %lld", &a, &b);

  /* Euclid: find the gcd first */
  long long x = a, y = b;
  while (y != 0)
  {
    long long t = x % y;
    x = y;
    y = t;
  }

  /* lcm = a / gcd * b (divide first to avoid overflow) */
  printf("%lld\n", a / x * b);
  return 0;
}
