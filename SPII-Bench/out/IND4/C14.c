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
    double a, b, res;
    char op;
    scanf("%lf %c %lf", &a, &op, &b);
    if (op == '+') res = a + b;
    else if (op == '-') res = a - b;
    else if (op == '*') res = a * b;
    else if (op == '/') {
        if (b == 0) {
            printf("Error: division by zero\n");
            return 0;
        }
        res = a / b;
    } else {
        printf("Error: invalid operator\n");
        return 0;
    }
    if (res == (long long)res) printf("%lld\n", (long long)res);
    else printf("%g\n", res);

    return 0;
}
