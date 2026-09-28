/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <math.h>

static const char *money(double value, char *buf)
{
    if (!isinf(value) && floor(value) == value)
        sprintf(buf, "%lld", (long long) value);
    else
        sprintf(buf, "%.2f", value);
    return buf;
}

static int deposit(double *balance, double amount)
{
    if (amount <= 0) { printf("Invalid amount\n"); return 0; }
    *balance += amount;
    return 1;
}

static int withdraw(double *balance, double amount)
{
    if (amount <= 0) { printf("Invalid amount\n"); return 0; }
    if (amount > *balance) { printf("Insufficient funds\n"); return 0; }
    *balance -= amount;
    return 1;
}

int main(void)
{
    double balance = 0;
    int transactions = 0;
    char a[64], b[64];
    int choice;

    while (scanf("%d", &choice) == 1) {
        double amount;
        switch (choice) {
        case 1:
            scanf("%lf", &amount);
            if (deposit(&balance, amount)) {
                transactions++;
                printf("Deposited %s, Balance = %s\n", money(amount, a), money(balance, b));
            }
            break;
        case 2:
            scanf("%lf", &amount);
            if (withdraw(&balance, amount)) {
                transactions++;
                printf("Withdrew %s, Balance = %s\n", money(amount, a), money(balance, b));
            }
            break;
        case 3:
            printf("Balance = %s\n", money(balance, a));
            break;
        case 4:
            printf("Transactions = %d\n", transactions);
            printf("Final balance = %s\n", money(balance, a));
            return 0;
        default:
            break;
        }
    }
    return 0;
}
