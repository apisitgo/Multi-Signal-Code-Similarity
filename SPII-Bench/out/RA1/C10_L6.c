/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Geometry Area #1 - Rectangle
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// format a double: whole numbers without decimals, else 2 decimal places
static void formatNum(double val, char *out)
{
    if (val == floor(val) && !isinf(val)) {
        sprintf(out, "%lld", (long long) val);
        return;
    }
    sprintf(out, "%.2f", val);
}

static double rectArea(double width, double height)
{
    return width * height;
}

static double rectPerimeter(double width, double height)
{
    double s = width + height;
    return s * 2;
}

static void report(const char *label, double value)
{
    char buf[64];
    formatNum(value, buf);
    printf("%s = %s\n", label, buf);
}

int main(void)
{
    double width = 0, height = 0;
    scanf("%lf %lf", &width, &height);

    report("Area", rectArea(width, height));
    report("Perimeter", rectPerimeter(width, height));

    return 0;
}
