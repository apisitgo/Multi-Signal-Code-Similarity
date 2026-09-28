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
    if (isinf(val) || floor(val) != val) {
        snprintf(dst, TEXTLEN, "%.2f", val);
        return;
    }
    snprintf(dst, TEXTLEN, "%lld", (long long)val);
}

/* compute lhs <oper> rhs; returns NULL on success or the error text */
static const char *compute(double lhs, const char *oper, double rhs, double *result) {
    const double ZERO = 0.0;
    /* only single-character operators are valid */
    if (strlen(oper) != 1)
        return "Error: invalid operator";
    switch (oper[0]) {
    case '+': *result = lhs + rhs; return NULL;
    case '-': *result = lhs - rhs; return NULL;
    case '*': *result = lhs * rhs; return NULL;
    case '/':
        if (rhs != ZERO) {
            *result = lhs / rhs;
            return NULL;
        }
        return "Error: division by zero";
    default:
        return "Error: invalid operator";
    }
}

static void print_result(double result) {
    char text[TEXTLEN];
    num_to_str(result, text);
    puts(text);
}

int main(void) {
    double lhs;
    double rhs;
    double result = 0.0;
    char oper[OPLEN];
    const char *err;

    /* input: number operator number, read in one call */
    scanf("%lf %15s %lf", &lhs, oper, &rhs);

    err = compute(lhs, oper, rhs, &result);
    if (err == NULL) {
        print_result(result);
        return 0;
    }
    puts(err);
    return 0;
}
