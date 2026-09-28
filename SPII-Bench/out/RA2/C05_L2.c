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
  long long m, n;
  scanf("%lld %lld", &m, &n);

  /* Euclid: find the gcd first */
  long long u = m, v = n;
  while (v != 0)
  {
    long long rem = u % v;
    u = v;
    v = rem;
  }

  /* lcm = m / gcd * n (divide first to avoid overflow) */
  printf("%lld\n", m / u * n);
  return 0;
}
