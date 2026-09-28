// total area of many shapes
#include <stdio.h>

#define PI 3.14159265358979323846

double circle(double r) { return PI * r * r; }
double rectangle(double w, double h) { return w * h; }
double triangle(double b, double h) { return 0.5 * b * h; }

int main(void)
{
    int n, i, type;
    double x, y;
    double total = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%lf", &x);
            total += circle(x);
        }
        if (type == 2) {
            scanf("%lf %lf", &x, &y);
            total += rectangle(x, y);
        }
        if (type == 3) {
            scanf("%lf %lf", &x, &y);
            total += triangle(x, y);
        }
    }
    printf("Total area = %.2f\n", total);

    return 0;
}
