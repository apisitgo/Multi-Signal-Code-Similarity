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
    if (!isinf(val) && val == floor(val)) {
        sprintf(out, "%lld", (long long) val);
    } else {
        sprintf(out, "%.2f", val);
    }
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

int main(void)
{
    double width = 0, height = 0;
    char areaStr[64], periStr[64];

    scanf("%lf %lf", &width, &height);

    formatNum(rectArea(width, height), areaStr);
    formatNum(rectPerimeter(width, height), periStr);

    printf("Area = %s\n", areaStr);
    printf("Perimeter = %s\n", periStr);

    return 0;
}
