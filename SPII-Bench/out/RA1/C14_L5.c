/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Basic Calculator #2 - Simple Calculator
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// format a double: whole numbers without decimals, else 2 decimal places
static void formatNum(double val, char *out)
{
    if (!isinf(val) && val == floor(val)) {
        sprintf(out, "%lld", (long long) val);
    } else {
        sprintf(out, "%.2f", val);
    }
}

// returns 1 on success (writes *result), 0 on error (already printed the message)
static int applyOp(double lhs, const char *oper, double rhs, double *result)
{
    if (strcmp(oper, "+") == 0) {
        *result = lhs + rhs;
        return 1;
    }
    if (strcmp(oper, "-") == 0) {
        *result = lhs - rhs;
        return 1;
    }
    if (strcmp(oper, "*") == 0) {
        *result = lhs * rhs;
        return 1;
    }
    if (strcmp(oper, "/") == 0) {
        if (rhs == 0) {
            printf("Error: division by zero\n");
            return 0;
        }
        *result = lhs / rhs;
        return 1;
    }
    printf("Error: invalid operator\n");
    return 0;
}

int main(void)
{
    double lhs = 0, rhs = 0, result = 0;
    char oper[16];

    scanf("%lf %15s %lf", &lhs, oper, &rhs);

    if (!applyOp(lhs, oper, rhs, &result)) {
        return 0;
    }

    char out[64];
    formatNum(result, out);
    printf("%s\n", out);

    return 0;
}
