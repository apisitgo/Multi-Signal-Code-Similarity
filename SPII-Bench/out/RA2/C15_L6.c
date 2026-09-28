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

double balance;
long numTrans;

// whole amounts are shown without decimals
static void money_str(double x, char *out)
{
  if (isinf(x) || floor(x) != x)
  {
    snprintf(out, TXT_SIZE, "%.2f", x);
    return;
  }
  snprintf(out, TXT_SIZE, "%lld", (long long) x);
}

// print "<verb> <amount>, Balance = <balance>"
static void report(const char *verb, double amount)
{
  char amtTxt[TXT_SIZE], balTxt[TXT_SIZE];
  money_str(balance, balTxt);
  money_str(amount, amtTxt);
  printf("%s %s, Balance = %s\n", verb, amtTxt, balTxt);
}

// deposit (sign = +1) or withdraw (sign = -1) with validation
static void transaction(int sign)
{
  double amount;
  const char *problem = NULL;

  scanf("%lf", &amount);
  if (!(amount > 0))
    problem = "Invalid amount";
  else if (sign < 0 && balance < amount)
    problem = "Insufficient funds";

  if (problem)
  {
    puts(problem);
    return;
  }
  numTrans = numTrans + 1;
  balance = balance + sign * amount;
  report(sign > 0 ? "Deposited" : "Withdrew", amount);
}

static void show_balance(const char *label)
{
  char balTxt[TXT_SIZE];
  money_str(balance, balTxt);
  printf("%s = %s\n", label, balTxt);
}

int main(void)
{
  int cmd;
  int running = 1;

  numTrans = 0;
  balance = 0.0;

  // menu loop: 1 deposit, 2 withdraw, 3 balance, 4 quit
  while (running)
  {
    scanf("%d", &cmd);

    switch (cmd)
    {
    case 1:
      transaction(+1);
      break;
    case 2:
      transaction(-1);
      break;
    case 3:
      show_balance("Balance");
      break;
    case 4:
      printf("Transactions = %ld\n", numTrans);
      show_balance("Final balance");
      running = 0;
      break;
    default:
      break;
    }
  }
  return 0;
}
