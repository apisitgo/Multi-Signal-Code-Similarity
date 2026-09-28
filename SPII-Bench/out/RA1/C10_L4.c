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
    if (!isinf(val) && val == floor(val)) sprintf(out, "%lld", (long long) val);
    else sprintf(out, "%.2f", val);
}

static double rectArea(double width, double height)
{
    return width * height;
}

static double rectPerimeter(double width, double height)
{
    return 2 * (width + height);
}

int main(void)
{
    double width = 0, height = 0;
    scanf("%lf", &width);
    scanf("%lf", &height);

    char areaStr[64], periStr[64];
    formatNum(rectArea(width, height), areaStr);
    printf("Area = %s\n", areaStr);
    formatNum(rectPerimeter(width, height), periStr);
    printf("Perimeter = %s\n", periStr);

    return 0;
}
