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
    double width, height;
    printf("Enter width: ");
    scanf("%lf", &width);
    printf("Enter height: ");
    scanf("%lf", &height);

    double area = width * height;
    double perimeter = 2 * (width + height);

    if (area == (long long) area) {
        printf("Area = %lld\n", (long long) area);
    } else {
        printf("Area = %.2f\n", area);
    }

    if (perimeter == (long long) perimeter) {
        printf("Perimeter = %lld\n", (long long) perimeter);
    } else {
        printf("Perimeter = %.2f\n", perimeter);
    }

    return 0;
}
