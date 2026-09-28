/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <math.h>

static void print_measure(const char *label, double value)
{
    if (!isinf(value) && floor(value) == value)
        printf("%s = %lld\n", label, (long long) value);
    else
        printf("%s = %.2f\n", label, value);
}

int main(void)
{
    double width = 0, height = 0;
    scanf("%lf %lf", &width, &height);
    print_measure("Area", width * height);
    print_measure("Perimeter", 2 * (width + height));
    return 0;
}
