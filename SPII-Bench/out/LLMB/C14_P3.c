// simple calculator: number operator number
#include <stdio.h>
#include <string.h>

void show(double x)
{
    if (x == (long long) x)
        printf("%lld\n", (long long) x);
    else
        printf("%.2f\n", x);
}

int main(void)
{
    double a, b;
    char op[16];

    scanf("%lf %15s %lf", &a, op, &b);

    if (strcmp(op, "+") == 0)
        show(a + b);
    else if (strcmp(op, "-") == 0)
        show(a - b);
    else if (strcmp(op, "*") == 0)
        show(a * b);
    else if (strcmp(op, "/") == 0) {
        if (b == 0)
            printf("Error: division by zero\n");
        else
            show(a / b);
    }
    else
        printf("Error: invalid operator\n");

    return 0;
}
