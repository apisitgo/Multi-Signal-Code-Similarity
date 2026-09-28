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

int main(void)
{
    double width, height;
    double area, perimeter;
    char areaStr[64], periStr[64];

    width = 0;
    height = 0;
    scanf("%lf", &width);
    scanf("%lf", &height);

    area = width * height;
    perimeter = 2 * (width + height);

    formatNum(area, areaStr);
    printf("Area = %s\n", areaStr);
    formatNum(perimeter, periStr);
    printf("Perimeter = %s\n", periStr);

    return 0;
}
