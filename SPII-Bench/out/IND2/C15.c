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
    int balance = 0;
    int transactions = 0;
    int choice;
    int running = 1;

    while (running) {
        scanf("%d", &choice);

        if (choice == 1) {
            int amount;
            scanf("%d", &amount);
            if (amount <= 0) {
                printf("Invalid amount\n");
            } else {
                balance = balance + amount;
                transactions = transactions + 1;
                printf("Deposited %d, Balance = %d\n", amount, balance);
            }
        } else if (choice == 2) {
            int amount;
            scanf("%d", &amount);
            if (amount <= 0) {
                printf("Invalid amount\n");
            } else if (amount > balance) {
                printf("Insufficient funds\n");
            } else {
                balance = balance - amount;
                transactions = transactions + 1;
                printf("Withdrew %d, Balance = %d\n", amount, balance);
            }
        } else if (choice == 3) {
            printf("Balance = %d\n", balance);
        } else if (choice == 4) {
            printf("Transactions = %d\n", transactions);
            printf("Final balance = %d\n", balance);
            running = 0;
        }
    }

    return 0;
}
