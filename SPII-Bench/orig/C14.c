/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #2 — Simple Calculator
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static void fmt(double v, char *buf)
{
    if (!isinf(v) && v == floor(v)) sprintf(buf, "%lld", (long long) v);
    else sprintf(buf, "%.2f", v);
}

int main(void)
{
    double a, b;
    char op[16];
    scanf("%lf", &a);
    scanf("%15s", op);
    scanf("%lf", &b);

    double r;
    if (strcmp(op, "+") == 0) {
        r = a + b;
    } else if (strcmp(op, "-") == 0) {
        r = a - b;
    } else if (strcmp(op, "*") == 0) {
        r = a * b;
    } else if (strcmp(op, "/") == 0) {
        if (b == 0) { printf("Error: division by zero\n"); return 0; }
        r = a / b;
    } else {
        printf("Error: invalid operator\n");
        return 0;
    }

    char buf[64];
    fmt(r, buf);
    printf("%s\n", buf);

    return 0;
}
