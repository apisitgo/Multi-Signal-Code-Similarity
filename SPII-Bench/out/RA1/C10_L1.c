/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Geometry Area #1 - Rectangle
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// format a double: whole numbers without decimals, else 2 decimal places
static void fmt(double v, char *buf)
{
    if (!isinf(v) && v == floor(v)) sprintf(buf, "%lld", (long long) v);
    else sprintf(buf, "%.2f", v);
}

int main(void)
{
    double w = 0, h = 0;
    scanf("%lf", &w);
    scanf("%lf", &h);

    char buf1[64], buf2[64];
    fmt(w * h, buf1);
    printf("Area = %s\n", buf1);
    fmt(2 * (w + h), buf2);
    printf("Perimeter = %s\n", buf2);

    return 0;
}
