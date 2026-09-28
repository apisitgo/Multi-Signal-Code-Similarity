/*
 * ------------------------------------------------------------
 *   Programming Fundamentals - Lab exercise
 *   Task    : Simple Bank Account #3 -- With Validation
 *   Student : <student id> <full name>
 * ------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// whole amounts are shown without decimals
static void fmt(double v, char *buf)
{
  if (!isinf(v) && v == floor(v))
    sprintf(buf, "%lld", (long long) v);
  else
    sprintf(buf, "%.2f", v);
}

int main(void)
{
  double bal = 0;
  int txn = 0;
  char buf1[64], buf2[64];

  // menu loop: 1 deposit, 2 withdraw, 3 balance, 4 quit
  while (1)
  {
    int c;
    scanf("%d", &c);

    if (c == 1)
    {
      double a;
      scanf("%lf", &a);
      if (a <= 0)
      {
        printf("Invalid amount\n");
        continue;
      }
      bal += a;
      txn++;
      fmt(a, buf1);
      fmt(bal, buf2);
      printf("Deposited %s, Balance = %s\n", buf1, buf2);
    }
    else if (c == 2)
    {
      double a;
      scanf("%lf", &a);
      if (a <= 0)
      {
        printf("Invalid amount\n");
        continue;
      }
      if (a > bal)
      {
        printf("Insufficient funds\n");
        continue;
      }
      bal -= a;
      txn++;
      fmt(a, buf1);
      fmt(bal, buf2);
      printf("Withdrew %s, Balance = %s\n", buf1, buf2);
    }
    else if (c == 3)
    {
      fmt(bal, buf1);
      printf("Balance = %s\n", buf1);
    }
    else if (c == 4)
    {
      fmt(bal, buf1);
      printf("Transactions = %d\n", txn);
      printf("Final balance = %s\n", buf1);
      break;
    }
  }
  return 0;
}
