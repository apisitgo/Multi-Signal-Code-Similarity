/*
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #2 -- Simple Calculator
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OPLEN 16
#define TEXTLEN 64

/* print integers without decimals, anything else with two */
static void num_to_str(double val, char *dst) {
    if (!isinf(val) && val == floor(val))
        sprintf(dst, "%lld", (long long)val);
    else
        sprintf(dst, "%.2f", val);
}

int main(void) {
    double lhs;
    double rhs;
    double result = 0.0;
    char oper[OPLEN];
    char text[TEXTLEN];
    const double ZERO = 0.0;

    /* input: number operator number */
    scanf("%lf", &lhs);
    scanf("%15s", oper);
    scanf("%lf", &rhs);

    if (strcmp(oper, "+") == 0)
        result = lhs + rhs;
    else if (strcmp(oper, "-") == 0)
        result = lhs - rhs;
    else if (strcmp(oper, "*") == 0)
        result = lhs * rhs;
    else if (strcmp(oper, "/") == 0) {
        if (rhs == ZERO) {
            printf("Error: division by zero\n");
            return 0;
        }
        result = lhs / rhs;
    }
    else {
        printf("Error: invalid operator\n");
        return 0;
    }

    num_to_str(result, text);
    printf("%s\n", text);
    return 0;
}
