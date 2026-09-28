#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void format_number(double number_value, char *destination_buffer)
{
    if (!isinf(number_value) && number_value == floor(number_value)) {
        sprintf(destination_buffer, "%lld", (long long) number_value);
    } else {
        sprintf(destination_buffer, "%.2f", number_value);
    }
}

typedef struct {
    double balance;
    int transaction_count;
} Account;

static void handle_deposit(Account *account)
{
    double amount_value;
    scanf("%lf", &amount_value);
    if (amount_value <= 0) {
        printf("Invalid amount\n");
        return;
    }
    account->balance += amount_value;
    account->transaction_count++;
    char amount_text[64], balance_text[64];
    format_number(amount_value, amount_text);
    format_number(account->balance, balance_text);
    printf("Deposited %s, Balance = %s\n", amount_text, balance_text);
}

static void handle_withdraw(Account *account)
{
    double amount_value;
    scanf("%lf", &amount_value);
    if (amount_value <= 0) {
        printf("Invalid amount\n");
        return;
    }
    if (amount_value > account->balance) {
        printf("Insufficient funds\n");
        return;
    }
    account->balance -= amount_value;
    account->transaction_count++;
    char amount_text[64], balance_text[64];
    format_number(amount_value, amount_text);
    format_number(account->balance, balance_text);
    printf("Withdrew %s, Balance = %s\n", amount_text, balance_text);
}

static void handle_show(const Account *account)
{
    char balance_text[64];
    format_number(account->balance, balance_text);
    printf("Balance = %s\n", balance_text);
}

static void handle_final(const Account *account)
{
    char balance_text[64];
    format_number(account->balance, balance_text);
    printf("Transactions = %d\n", account->transaction_count);
    printf("Final balance = %s\n", balance_text);
}

int main(void)
{
    Account account = {0.0, 0};

    for (;;) {
        int command_code;
        scanf("%d", &command_code);

        if (command_code == 1) {
            handle_deposit(&account);
        } else if (command_code == 2) {
            handle_withdraw(&account);
        } else if (command_code == 3) {
            handle_show(&account);
        } else if (command_code == 4) {
            handle_final(&account);
            break;
        }
    }

    return 0;
}
