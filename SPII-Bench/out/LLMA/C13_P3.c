#include <stdio.h>

int main(void)
{
    /* total area of several shapes */
    double pi = 3.14159265358979323846;
    int n;
    scanf("%d", &n);

    double total = 0;
    int i = 0;
    while (i < n) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            double r;
            scanf("%lf", &r);
            total = total + pi * r * r;
        }
        if (t == 2) {
            double w, h;
            scanf("%lf", &w);
            scanf("%lf", &h);
            total = total + w * h;
        }
        if (t == 3) {
            double b, h;
            scanf("%lf", &b);
            scanf("%lf", &h);
            total = total + 0.5 * b * h;
        }
        i = i + 1;
    }

    printf("Total area = %.2f\n", total);
    return 0;
}
