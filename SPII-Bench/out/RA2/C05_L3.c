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
  long long m;
  long long n;
  long long u, v, rem;
  long long lcm;

  scanf("%lld %lld", &m, &n);

  /* Euclid: find the gcd first */
  u = m;
  v = n;
  while (v != 0)
  {
    rem = u % v;
    u = v;
    v = rem;
  }

  /* lcm = m / gcd * n (divide first to avoid overflow) */
  lcm = m / u * n;
  printf("%lld\n", lcm);
  return 0;
}
