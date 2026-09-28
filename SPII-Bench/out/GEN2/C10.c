/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #1 — Rectangle
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    double w, h;
    if (scanf("%lf %lf", &w, &h) != 2) return 1;

    double area = w * h;
    double perimeter = 2 * (w + h);
    printf("Area = %g\n", area);
    printf("Perimeter = %g\n", perimeter);

    return 0;
}
