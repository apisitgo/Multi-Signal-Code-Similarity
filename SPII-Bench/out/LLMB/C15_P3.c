// bank account program
// 1 deposit, 2 withdraw, 3 show balance, 4 exit
#include <stdio.h>

void print_amount(double x)
{
    if (x == (long long) x)
        printf("%lld", (long long) x);
    else
        printf("%.2f", x);
}

int main(void)
{
    double balance = 0, amount;
    int count = 0;
    int choice;

    do {
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("Invalid amount\n");
            } else {
                balance += amount;
                count++;
                printf("Deposited ");
                print_amount(amount);
                printf(", Balance = ");
                print_amount(balance);
                printf("\n");
            }
        }
        else if (choice == 2) {
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("Invalid amount\n");
            } else if (amount > balance) {
                printf("Insufficient funds\n");
            } else {
                balance -= amount;
                count++;
                printf("Withdrew ");
                print_amount(amount);
                printf(", Balance = ");
                print_amount(balance);
                printf("\n");
            }
        }
        else if (choice == 3) {
            printf("Balance = ");
            print_amount(balance);
            printf("\n");
        }
    } while (choice != 4);

    printf("Transactions = %d\n", count);
    printf("Final balance = ");
    print_amount(balance);
    printf("\n");

    return 0;
}
