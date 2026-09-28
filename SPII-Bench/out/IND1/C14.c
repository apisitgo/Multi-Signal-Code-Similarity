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
    int a, b;
    char op;

    scanf("%d", &a);
    scanf(" %c", &op);
    scanf("%d", &b);

    double result;
    int valid = 1;

    if (op == '+') {
        result = a + b;
    } else if (op == '-') {
        result = a - b;
    } else if (op == '*') {
        result = a * b;
    } else if (op == '/') {
        if (b == 0) {
            printf("Error: division by zero\n");
            return 0;
        }
        result = (double)a / b;
    } else {
        printf("Error: invalid operator\n");
        return 0;
    }

    // Check if result is integer
    if (result == (int)result) {
        printf("%d\n", (int)result);
    } else {
        printf("%f\n", result);
    }

    return 0;
}
