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

#define TXT_SIZE 64

// whole amounts are shown without decimals
static void money_str(double x, char *out)
{
  if (!isinf(x) && x == floor(x))
    sprintf(out, "%lld", (long long) x);
  else
    sprintf(out, "%.2f", x);
}

double balance;
long numTrans;

int main(void)
{
  char amtTxt[TXT_SIZE];
  char balTxt[TXT_SIZE];
  int cmd;
  double amount;
  const double MIN_AMOUNT = 0;

  balance = 0.0;
  numTrans = 0;

  // menu loop: 1 deposit, 2 withdraw, 3 balance, 4 quit
  while (1)
  {
    scanf("%d", &cmd);

    if (cmd == 1)
    {
      scanf("%lf", &amount);
      if (amount <= MIN_AMOUNT)
      {
        printf("Invalid amount\n");
        continue;
      }
      balance += amount;
      numTrans++;
      money_str(amount, amtTxt);
      money_str(balance, balTxt);
      printf("Deposited %s, Balance = %s\n", amtTxt, balTxt);
    }
    else if (cmd == 2)
    {
      scanf("%lf", &amount);
      if (amount <= MIN_AMOUNT)
      {
        printf("Invalid amount\n");
        continue;
      }
      if (amount > balance)
      {
        printf("Insufficient funds\n");
        continue;
      }
      balance -= amount;
      numTrans++;
      money_str(amount, amtTxt);
      money_str(balance, balTxt);
      printf("Withdrew %s, Balance = %s\n", amtTxt, balTxt);
    }
    else if (cmd == 3)
    {
      money_str(balance, amtTxt);
      printf("Balance = %s\n", amtTxt);
    }
    else if (cmd == 4)
    {
      money_str(balance, amtTxt);
      printf("Transactions = %ld\n", numTrans);
      printf("Final balance = %s\n", amtTxt);
      break;
    }
  }
  return 0;
}
