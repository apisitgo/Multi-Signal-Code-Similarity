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
    char op;
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) return 1;

    double result;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                printf("Error: division by zero\n");
                return 0;
            }
            result = a / b;
            break;
        default:
            printf("Error: invalid operator\n");
            return 0;
    }

    if (result == (double)(long long)result)
        printf("%lld\n", (long long)result);
    else
        printf("%.2f\n", result);

    return 0;
}
