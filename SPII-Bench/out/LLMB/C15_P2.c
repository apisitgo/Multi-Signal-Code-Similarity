/* Bank account command loop with amount validation. */
#include <stdio.h>
#include <math.h>

static const char *money(double x, char *dst)
{
    if (isinf(x) || floor(x) != x)
        sprintf(dst, "%.2f", x);
    else
        sprintf(dst, "%lld", (long long) x);
    return dst;
}

int main(void)
{
    double funds = 0.0;
    int ops = 0, cmd;
    char s1[64], s2[64];

    for (;;) {
        scanf("%d", &cmd);
        if (cmd == 3) {
            printf("Balance = %s\n", money(funds, s1));
        } else if (cmd == 4) {
            printf("Transactions = %d\n", ops);
            printf("Final balance = %s\n", money(funds, s1));
            break;
        } else if (cmd == 1 || cmd == 2) {
            double amt;
            scanf("%lf", &amt);
            if (amt <= 0) {
                puts("Invalid amount");
            } else if (cmd == 2 && amt > funds) {
                puts("Insufficient funds");
            } else {
                funds += (cmd == 1) ? amt : -amt;
                ops++;
                printf("%s %s, Balance = %s\n", cmd == 1 ? "Deposited" : "Withdrew",
                       money(amt, s1), money(funds, s2));
            }
        }
    }
    return 0;
}
