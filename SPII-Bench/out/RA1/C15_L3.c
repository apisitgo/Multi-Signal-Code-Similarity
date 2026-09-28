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

int main(void)
{
    double balance;
    int txnCount;
    char strA[64], strB[64];
    int loopsRun = 0;      // redundant counter

    balance = 0;
    txnCount = 0;

    while (1) {
        int choice;
        scanf("%d", &choice);
        loopsRun++;
        if (choice == 1) {
            double amt;
            scanf("%lf", &amt);
            if (amt <= 0) { printf("Invalid amount\n"); continue; }
            balance += amt; txnCount++;
            formatNum(amt, strA); formatNum(balance, strB);
            printf("Deposited %s, Balance = %s\n", strA, strB);
        } else if (choice == 2) {
            double amt;
            scanf("%lf", &amt);
            if (amt <= 0) { printf("Invalid amount\n"); continue; }
            if (amt > balance) { printf("Insufficient funds\n"); continue; }
            balance -= amt; txnCount++;
            formatNum(amt, strA); formatNum(balance, strB);
            printf("Withdrew %s, Balance = %s\n", strA, strB);
        } else if (choice == 3) {
            formatNum(balance, strA);
            printf("Balance = %s\n", strA);
        } else if (choice == 4) {
            formatNum(balance, strA);
            printf("Transactions = %d\n", txnCount);
            printf("Final balance = %s\n", strA);
            break;
        }
    }

    (void) loopsRun;
    return 0;
}
