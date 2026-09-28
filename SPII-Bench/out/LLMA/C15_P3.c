#include <stdio.h>
#include <math.h>

int show(double v, char *buf)
{
    if (v == (long long) v) {
        sprintf(buf, "%lld", (long long) v);
    } else {
        sprintf(buf, "%.2f", v);
    }
    return 0;
}

int main(void)
{
    /* bank account with validation */
    double bal = 0;
    int txn = 0;
    char buf1[64];
    char buf2[64];

    while (1) {
        int c;
        scanf("%d", &c);

        if (c == 1) {
            double a;
            scanf("%lf", &a);
            if (a <= 0) {
                printf("Invalid amount\n");
                continue;
            }
            bal = bal + a;
            txn = txn + 1;
            show(a, buf1);
            show(bal, buf2);
            printf("Deposited %s, Balance = %s\n", buf1, buf2);
        }
        else if (c == 2) {
            double a;
            scanf("%lf", &a);
            if (a <= 0) {
                printf("Invalid amount\n");
                continue;
            }
            if (a > bal) {
                printf("Insufficient funds\n");
                continue;
            }
            bal = bal - a;
            txn = txn + 1;
            show(a, buf1);
            show(bal, buf2);
            printf("Withdrew %s, Balance = %s\n", buf1, buf2);
        }
        else if (c == 3) {
            show(bal, buf1);
            printf("Balance = %s\n", buf1);
        }
        else if (c == 4) {
            show(bal, buf1);
            printf("Transactions = %d\n", txn);
            printf("Final balance = %s\n", buf1);
            break;
        }
    }

    return 0;
}
