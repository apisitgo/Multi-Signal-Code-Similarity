#include <stdio.h>
#include <math.h>

static void render(double v, char *out) {
    if (!isinf(v) && v == floor(v)) sprintf(out, "%lld", (long long) v);
    else sprintf(out, "%.2f", v);
}

int main(void) {
    double bal = 0;
    int count = 0;
    char b1[64], b2[64];

    while (1) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            double amt;
            scanf("%lf", &amt);
            if (amt <= 0) { printf("Invalid amount\n"); continue; }
            bal += amt;
            count++;
            render(amt, b1); render(bal, b2);
            printf("Deposited %s, Balance = %s\n", b1, b2);
        } else if (cmd == 2) {
            double amt;
            scanf("%lf", &amt);
            if (amt <= 0) { printf("Invalid amount\n"); continue; }
            if (amt > bal) { printf("Insufficient funds\n"); continue; }
            bal -= amt;
            count++;
            render(amt, b1); render(bal, b2);
            printf("Withdrew %s, Balance = %s\n", b1, b2);
        } else if (cmd == 3) {
            render(bal, b1);
            printf("Balance = %s\n", b1);
        } else if (cmd == 4) {
            render(bal, b1);
            printf("Transactions = %d\n", count);
            printf("Final balance = %s\n", b1);
            break;
        }
    }
    return 0;
}
