// rectangle area and perimeter
#include <stdio.h>

void show(char *name, double x)
{
    // if it is a whole number don't print decimals
    if (x == (long long) x)
        printf("%s = %lld\n", name, (long long) x);
    else
        printf("%s = %.2f\n", name, x);
}

int main(void)
{
    double w, h, area, peri;
    scanf("%lf", &w);
    scanf("%lf", &h);

    area = w * h;
    peri = 2 * w + 2 * h;

    show("Area", area);
    show("Perimeter", peri);
    return 0;
}
