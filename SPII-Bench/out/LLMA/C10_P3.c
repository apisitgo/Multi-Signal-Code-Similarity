#include <stdio.h>
#include <math.h>

int main(void)
{
    /* area and perimeter of rectangle */
    double w, h;
    scanf("%lf", &w);
    scanf("%lf", &h);

    double area = w * h;
    double peri = 2 * (w + h);

    if (area == (long long) area) {
        printf("Area = %lld\n", (long long) area);
    } else {
        printf("Area = %.2f\n", area);
    }

    if (peri == (long long) peri) {
        printf("Perimeter = %lld\n", (long long) peri);
    } else {
        printf("Perimeter = %.2f\n", peri);
    }

    return 0;
}
