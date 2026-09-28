/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <string.h>
#include <math.h>

static void print_number(double value)
{
    if (!isinf(value) && floor(value) == value)
        printf("%lld\n", (long long) value);
    else
        printf("%.2f\n", value);
}

int main(void)
{
    double lhs, rhs;
    char op[16];
    if (scanf("%lf %15s %lf", &lhs, op, &rhs) != 3) return 0;

    if (strlen(op) != 1) {
        printf("Error: invalid operator\n");
        return 0;
    }
    switch (op[0]) {
    case '+': print_number(lhs + rhs); break;
    case '-': print_number(lhs - rhs); break;
    case '*': print_number(lhs * rhs); break;
    case '/':
        if (rhs == 0) printf("Error: division by zero\n");
        else print_number(lhs / rhs);
        break;
    default:
        printf("Error: invalid operator\n");
    }
    return 0;
}
