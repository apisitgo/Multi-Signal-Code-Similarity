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
    
        while (scanf("%d", &choice) != EOF && choice != 4) {
            if (choice == 1) {
                int amount;
                scanf("%d", &amount);
                if (amount <= 0) {
                    printf("Invalid amount\n");
                } else {
                    balance += amount;
                    transactions++;
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
                    balance -= amount;
                    transactions++;
                    printf("Withdrew %d, Balance = %d\n", amount, balance);
                }
            }
        }
        printf("Transactions = %d\n", transactions);
        printf("Final balance = %d\n", balance);


    return 0;
}
