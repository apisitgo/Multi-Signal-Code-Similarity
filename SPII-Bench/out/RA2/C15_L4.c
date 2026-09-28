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
  if (!isinf(x) && x == floor(x))
    sprintf(out, "%lld", (long long) x);
  else
    sprintf(out, "%.2f", x);
}

// read an amount; returns 0 (after printing a message) if it is not positive
static int read_amount(double *amount)
{
  scanf("%lf", amount);
  if (*amount <= 0)
  {
    printf("Invalid amount\n");
    return 0;
  }
  return 1;
}

// apply a change and print "<verb> <amount>, Balance = <balance>"
static void apply(const char *verb, double amount, double delta)
{
  char amtTxt[TXT_SIZE], balTxt[TXT_SIZE];
  balance += delta;
  numTrans++;
  money_str(amount, amtTxt);
  money_str(balance, balTxt);
  printf("%s %s, Balance = %s\n", verb, amtTxt, balTxt);
}

static void deposit(void)
{
  double amount;
  if (read_amount(&amount))
    apply("Deposited", amount, amount);
}

static void withdraw(void)
{
  double amount;
  if (!read_amount(&amount))
    return;
  if (amount > balance)
  {
    printf("Insufficient funds\n");
    return;
  }
  apply("Withdrew", amount, -amount);
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

  balance = 0.0;
  numTrans = 0;

  // menu loop: 1 deposit, 2 withdraw, 3 balance, 4 quit
  while (1)
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
