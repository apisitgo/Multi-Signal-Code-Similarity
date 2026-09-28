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
    long long balance = 0;
    int transactions = 0;
    int choice;

    while (scanf("%d", &choice) == 1) {
        if (choice == 1 || choice == 2) {
            long long amount;
            if (scanf("%lld", &amount) != 1) break;
            if (amount <= 0) {
                printf("Invalid amount\n");
            } else if (choice == 1) {
                balance += amount;
                transactions++;
                printf("Deposited %lld, Balance = %lld\n", amount, balance);
            } else if (amount > balance) {
                printf("Insufficient funds\n");
            } else {
                balance -= amount;
                transactions++;
                printf("Withdrew %lld, Balance = %lld\n", amount, balance);
            }
        } else if (choice == 3) {
            printf("Balance = %lld\n", balance);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    printf("Transactions = %d\n", transactions);
    printf("Final balance = %lld\n", balance);

    return 0;
}
