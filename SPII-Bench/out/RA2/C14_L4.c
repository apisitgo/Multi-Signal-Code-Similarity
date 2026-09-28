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

/* compute lhs <oper> rhs; returns NULL on success or the error text */
static const char *compute(double lhs, const char *oper, double rhs, double *result) {
    const double ZERO = 0.0;
    if (strcmp(oper, "+") == 0)
        *result = lhs + rhs;
    else if (strcmp(oper, "-") == 0)
        *result = lhs - rhs;
    else if (strcmp(oper, "*") == 0)
        *result = lhs * rhs;
    else if (strcmp(oper, "/") == 0) {
        if (rhs == ZERO)
            return "Error: division by zero";
        *result = lhs / rhs;
    }
    else
        return "Error: invalid operator";
    return NULL;
}

static void print_result(double result) {
    char text[TEXTLEN];
    num_to_str(result, text);
    printf("%s\n", text);
}

int main(void) {
    double lhs;
    double rhs;
    double result = 0.0;
    char oper[OPLEN];
    const char *err;

    /* input: number operator number */
    scanf("%lf", &lhs);
    scanf("%15s", oper);
    scanf("%lf", &rhs);

    err = compute(lhs, oper, rhs, &result);
    if (err != NULL)
        printf("%s\n", err);
    else
        print_result(result);
    return 0;
}
