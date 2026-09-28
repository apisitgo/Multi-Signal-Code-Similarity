#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    /* simple calculator */
    double a, b;
    char op[16];
    scanf("%lf", &a);
    scanf("%15s", op);
    scanf("%lf", &b);

    double result = 0;
    int good = 1;

    if (strcmp(op, "+") == 0) {
        result = a + b;
    } else if (strcmp(op, "-") == 0) {
        result = a - b;
    } else if (strcmp(op, "*") == 0) {
        result = a * b;
    } else if (strcmp(op, "/") == 0) {
        if (b == 0) {
            printf("Error: division by zero\n");
            good = 0;
        } else {
            result = a / b;
        }
    } else {
        printf("Error: invalid operator\n");
        good = 0;
    }

    if (good == 1) {
        if (result == (long long) result) {
            printf("%lld\n", (long long) result);
        } else {
            printf("%.2f\n", result);
        }
    }

    return 0;
}
