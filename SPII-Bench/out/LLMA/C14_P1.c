#include <stdio.h>
#include <string.h>
#include <math.h>

static void render(double v, char *out) {
    if (!isinf(v) && v == floor(v)) sprintf(out, "%lld", (long long) v);
    else sprintf(out, "%.2f", v);
}

int main(void) {
    double x, y;
    char sym[16];
    scanf("%lf", &x);
    scanf("%15s", sym);
    scanf("%lf", &y);

    double res;
    if (!strcmp(sym, "+")) res = x + y;
    else if (!strcmp(sym, "-")) res = x - y;
    else if (!strcmp(sym, "*")) res = x * y;
    else if (!strcmp(sym, "/")) {
        if (y == 0) { printf("Error: division by zero\n"); return 0; }
        res = x / y;
    } else {
        printf("Error: invalid operator\n");
        return 0;
    }

    char buf[64];
    render(res, buf);
    printf("%s\n", buf);
    return 0;
}
