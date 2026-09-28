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
    int transaction_count = 0;

    while (1) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Deposit
            int amount;
            scanf("%d", &amount);

            if (amount <= 0) {
                printf("Invalid amount\n");
            } else {
                balance = balance + amount;
                printf("Deposited %d, Balance = %d\n", amount, balance);
                transaction_count++;
            }
        } else if (choice == 2) {
            // Withdraw
            int amount;
            scanf("%d", &amount);

            if (amount <= 0) {
                printf("Invalid amount\n");
            } else if (amount > balance) {
                printf("Insufficient funds\n");
            } else {
                balance = balance - amount;
                printf("Withdrew %d, Balance = %d\n", amount, balance);
                transaction_count++;
            }
        } else if (choice == 4) {
            // Exit
            printf("Transactions = %d\n", transaction_count);
            printf("Final balance = %d\n", balance);
            break;
        }
    }

    return 0;
}
