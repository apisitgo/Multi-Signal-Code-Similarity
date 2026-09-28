/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Simple Bank Account #3 — With Validation
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int c, n, b = 0, cnt = 0;
    while (scanf("%d", &c) == 1) {
        if (c == 1) {
            scanf("%d", &n);
            if (n <= 0) {
                printf("Invalid amount\n");
            } else {
                b += n;
                cnt++;
                printf("Deposited %d, Balance = %d\n", n, b);
            }
        } else if (c == 2) {
            scanf("%d", &n);
            if (n <= 0) {
                printf("Invalid amount\n");
            } else if (n > b) {
                printf("Insufficient funds\n");
            } else {
                b -= n;
                cnt++;
                printf("Withdrew %d, Balance = %d\n", n, b);
            }
        } else if (c == 3) {
            printf("Balance = %d\n", b);
        } else if (c == 4) {
            printf("Transactions = %d\n", cnt);
            printf("Final balance = %d\n", b);
            break;
        }
    }

    return 0;
}
