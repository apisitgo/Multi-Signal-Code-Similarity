/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #2 — Simple Calculator
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

void pres(double r)
{
    if (r == floor(r) && fabs(r) < 1e15) printf("%.0f\n", r);
    else printf("%.2f\n", r);
}

int main(void)
{
    double a, b;
    char op;
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) return 0;
    switch (op) {
    case '+': pres(a + b); break;
    case '-': pres(a - b); break;
    case '*': pres(a * b); break;
    case '/':
        if (b == 0) printf("Error: division by zero\n");
        else pres(a / b);
        break;
    default:
        printf("Error: invalid operator\n");
    }
    return 0;
}
