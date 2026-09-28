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
    if (!isinf(val) && val == floor(val)) {
        sprintf(out, "%lld", (long long) val);
    } else {
        sprintf(out, "%.2f", val);
    }
}

static void doDeposit(double *balance, int *txnCount)
{
    double amt;
    scanf("%lf", &amt);
    if (amt <= 0) {
        printf("Invalid amount\n");
        return;
    }
    *balance = *balance + amt;
    *txnCount = *txnCount + 1;
    char strA[64], strB[64];
    formatNum(amt, strA);
    formatNum(*balance, strB);
    printf("Deposited %s, Balance = %s\n", strA, strB);
}

static void doWithdraw(double *balance, int *txnCount)
{
    double amt;
    scanf("%lf", &amt);
    if (amt <= 0) {
        printf("Invalid amount\n");
        return;
    }
    if (amt > *balance) {
        printf("Insufficient funds\n");
        return;
    }
    *balance = *balance - amt;
    *txnCount = *txnCount + 1;
    char strA[64], strB[64];
    formatNum(amt, strA);
    formatNum(*balance, strB);
    printf("Withdrew %s, Balance = %s\n", strA, strB);
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
    int running = 1;

    while (running) {
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
            running = 0;
        }
    }

    return 0;
}
