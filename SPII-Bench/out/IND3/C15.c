/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Simple Bank Account #3 — With Validation
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

void pnum(double x)
{
    if (x == floor(x) && fabs(x) < 1e15) printf("%.0f", x);
    else printf("%.2f", x);
}

int main(void)
{
    int c, cnt = 0;
    double bal = 0, amt;
    while (scanf("%d", &c) == 1 && c != 4) {
        if (c == 1 || c == 2) {
            if (scanf("%lf", &amt) != 1) break;
            if (amt <= 0) { printf("Invalid amount\n"); continue; }
            if (c == 2 && amt > bal) { printf("Insufficient funds\n"); continue; }
            bal += c == 1 ? amt : -amt;
            cnt++;
            printf(c == 1 ? "Deposited " : "Withdrew ");
            pnum(amt);
            printf(", Balance = ");
            pnum(bal);
            printf("\n");
        } else if (c == 3) {
            printf("Balance = ");
            pnum(bal);
            printf("\n");
        } else {
            printf("Invalid choice\n");
        }
    }
    printf("Transactions = %d\n", cnt);
    printf("Final balance = ");
    pnum(bal);
    printf("\n");
    return 0;
}
