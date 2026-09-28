/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Simple Bank Account #3 - With Validation
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// format a double: whole numbers without decimals, else 2 decimal places
static void formatNum(double val, char *out)
{
    if (!isinf(val) && val == floor(val)) sprintf(out, "%lld", (long long) val);
    else sprintf(out, "%.2f", val);
}

// returns 0 if this transaction should be skipped (message already printed)
static int doDeposit(double *balance, int *txnCount)
{
    double amt;
    char strA[64], strB[64];
    scanf("%lf", &amt);
    if (amt <= 0) { printf("Invalid amount\n"); return 0; }
    *balance += amt; (*txnCount)++;
    formatNum(amt, strA); formatNum(*balance, strB);
    printf("Deposited %s, Balance = %s\n", strA, strB);
    return 1;
}

static int doWithdraw(double *balance, int *txnCount)
{
    double amt;
    char strA[64], strB[64];
    scanf("%lf", &amt);
    if (amt <= 0) { printf("Invalid amount\n"); return 0; }
    if (amt > *balance) { printf("Insufficient funds\n"); return 0; }
    *balance -= amt; (*txnCount)++;
    formatNum(amt, strA); formatNum(*balance, strB);
    printf("Withdrew %s, Balance = %s\n", strA, strB);
    return 1;
}

static void printBalance(double balance)
{
    char strA[64];
    formatNum(balance, strA);
    printf("Balance = %s\n", strA);
}

static void printSummary(double balance, int txnCount)
{
    char strA[64];
    formatNum(balance, strA);
    printf("Transactions = %d\n", txnCount);
    printf("Final balance = %s\n", strA);
}

int main(void)
{
    double balance = 0;
    int txnCount = 0;

    while (1) {
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            doDeposit(&balance, &txnCount);
        } else if (choice == 2) {
            doWithdraw(&balance, &txnCount);
        } else if (choice == 3) {
            printBalance(balance);
        } else if (choice == 4) {
            printSummary(balance, txnCount);
            break;
        }
    }

    return 0;
}
