/* ============================================================
   Programming Fundamentals - Lab exercise
   Task    : Algorithm #8 -- LCM (Least Common Multiple)
   Student : <student id> <full name>
   ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Euclid's algorithm */
static long long gcd(long long u, long long v)
{
  for (long long rem; v != 0; u = v, v = rem)
    rem = u % v;
  return u;
}

static long long lcm(long long m, long long n)
{
  long long g = gcd(m, n);
  long long q = m / g;   /* divide first to avoid overflow */
  return q * n;
}

int main(void)
{
  long long m;
  long long n;

  scanf("%lld", &m);
  scanf("%lld", &n);
  printf("%lld\n", lcm(m, n));
  return 0;
}
