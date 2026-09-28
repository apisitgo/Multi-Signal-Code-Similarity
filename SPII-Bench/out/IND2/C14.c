/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #2 — Simple Calculator
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    double a, b;
    char op[10];

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter operator (+ - * /): ");
    scanf("%s", op);
    printf("Enter b: ");
    scanf("%lf", &b);

    double result = 0.0;
    int has_error = 0;

    if (strcmp(op, "+") == 0) {
        result = a + b;
    } else if (strcmp(op, "-") == 0) {
        result = a - b;
    } else if (strcmp(op, "*") == 0) {
        result = a * b;
    } else if (strcmp(op, "/") == 0) {
        if (b == 0) {
            printf("Error: division by zero\n");
            has_error = 1;
        } else {
            result = a / b;
        }
    } else {
        printf("Error: invalid operator\n");
        has_error = 1;
    }

    if (!has_error) {
        if (result == (long long) result) {
            printf("%lld\n", (long long) result);
        } else {
            printf("%.2f\n", result);
        }
    }

    return 0;
}
