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
  long long rem;
  while (v != 0)
  {
    rem = u % v;
    u = v;
    v = rem;
  }
  return u;
}

static long long lcm(long long m, long long n)
{
  /* divide first to avoid overflow */
  return m / gcd(m, n) * n;
}

int main(void)
{
  long long m;
  long long n;

  scanf("%lld %lld", &m, &n);
  printf("%lld\n", lcm(m, n));
  return 0;
}
