#include <stdio.h>

int main(void)
{
    /* shape area menu */
    double pi = 3.14159265358979323846;
    int c;
    scanf("%d", &c);

    if (c == 1) {
        double r;
        scanf("%lf", &r);
        double a = pi * r * r;
        printf("Area = %.2f\n", a);
    } else {
        if (c == 2) {
            double w, h;
            scanf("%lf", &w);
            scanf("%lf", &h);
            double a = w * h;
            printf("Area = %.2f\n", a);
        } else {
            if (c == 3) {
                double b, h;
                scanf("%lf", &b);
                scanf("%lf", &h);
                double a = 0.5 * b * h;
                printf("Area = %.2f\n", a);
            } else {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}
