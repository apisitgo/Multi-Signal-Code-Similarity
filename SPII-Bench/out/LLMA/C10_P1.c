#include <stdio.h>
#include <math.h>

static void render(double v, char *out) {
    if (!isinf(v) && v == floor(v)) sprintf(out, "%lld", (long long) v);
    else sprintf(out, "%.2f", v);
}

int main(void) {
    double w, h;
    scanf("%lf %lf", &w, &h);
    char a[64], p[64];
    render(w * h, a);
    render(2 * (w + h), p);
    printf("Area = %s\n", a);
    printf("Perimeter = %s\n", p);
    return 0;
}
