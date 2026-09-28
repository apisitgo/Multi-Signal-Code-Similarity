/*
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #2 -- Simple Calculator
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* print integers without decimals, anything else with two */
static void num_to_str(double val, char *dst) {
    if (!isinf(val) && val == floor(val))
        sprintf(dst, "%lld", (long long)val);
    else
        sprintf(dst, "%.2f", val);
}

int main(void) {
    double lhs, rhs;
    char oper[16];

    /* input: number operator number */
    scanf("%lf", &lhs);
    scanf("%15s", oper);
    scanf("%lf", &rhs);

    double result;
    if (strcmp(oper, "+") == 0)
        result = lhs + rhs;
    else if (strcmp(oper, "-") == 0)
        result = lhs - rhs;
    else if (strcmp(oper, "*") == 0)
        result = lhs * rhs;
    else if (strcmp(oper, "/") == 0) {
        if (rhs == 0) {
            printf("Error: division by zero\n");
            return 0;
        }
        result = lhs / rhs;
    }
    else {
        printf("Error: invalid operator\n");
        return 0;
    }

    char text[64];
    num_to_str(result, text);
    printf("%s\n", text);
    return 0;
}
