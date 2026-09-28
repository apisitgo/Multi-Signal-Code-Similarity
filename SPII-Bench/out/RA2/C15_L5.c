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
  if (!isinf(x) && floor(x) == x)
    snprintf(out, TXT_SIZE, "%lld", (long long) x);
  else
    snprintf(out, TXT_SIZE, "%.2f", x);
}

// read an amount; returns 0 (after printing a message) if it is not positive
static int read_amount(double *amount)
{
  scanf("%lf", amount);
  if (*amount > 0)
    return 1;
  puts("Invalid amount");
  return 0;
}

// print "<verb> <amount>, Balance = <balance>"
static void report(const char *verb, double amount)
{
  char amtTxt[TXT_SIZE], balTxt[TXT_SIZE];
  money_str(balance, balTxt);
  money_str(amount, amtTxt);
  printf("%s %s, Balance = %s\n", verb, amtTxt, balTxt);
}

static void deposit(void)
{
  double amount;
  if (read_amount(&amount))
  {
    numTrans = numTrans + 1;
    balance = balance + amount;
    report("Deposited", amount);
  }
}

static void withdraw(void)
{
  double amount;
  if (!read_amount(&amount))
    return;
  if (balance < amount)
  {
    puts("Insufficient funds");
    return;
  }
  numTrans = numTrans + 1;
  balance = balance - amount;
  report("Withdrew", amount);
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

  numTrans = 0;
  balance = 0.0;

  // menu loop: 1 deposit, 2 withdraw, 3 balance, 4 quit
  for (;;)
  {
    scanf("%d", &cmd);

    if (cmd == 1)
      deposit();
    else if (cmd == 2)
      withdraw();
    else if (cmd == 3)
      show_balance("Balance");
    else if (cmd == 4)
    {
      printf("Transactions = %ld\n", numTrans);
      show_balance("Final balance");
      break;
    }
  }
  return 0;
}
