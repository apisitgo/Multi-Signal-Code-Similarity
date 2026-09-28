/* Two-operand calculator: a op b. */
#include <stdio.h>
#include <string.h>
#include <math.h>

static void print_result(double x)
{
    if (!isinf(x) && floor(x) == x)
        printf("%lld\n", (long long) x);
    else
        printf("%.2f\n", x);
}

int main(void)
{
    double lhs, rhs, out;
    char sym[16];

    scanf("%lf %15s %lf", &lhs, sym, &rhs);

    if (strlen(sym) != 1 || !strchr("+-*/", sym[0])) {
        puts("Error: invalid operator");
        return 0;
    }

    switch (sym[0]) {
    case '+': out = lhs + rhs; break;
    case '-': out = lhs - rhs; break;
    case '*': out = lhs * rhs; break;
    default:
        if (rhs == 0) {
            puts("Error: division by zero");
            return 0;
        }
        out = lhs / rhs;
    }
    print_result(out);
    return 0;
}
