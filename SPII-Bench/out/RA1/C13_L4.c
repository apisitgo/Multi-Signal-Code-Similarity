/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Geometry Area #3 - Total Area
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

static double readOneShapeArea(void)
{
    int shapeType;
    scanf("%d", &shapeType);
    if (shapeType == 1) {
        double radius;
        scanf("%lf", &radius);
        return PI * radius * radius;
    } else if (shapeType == 2) {
        double width, height;
        scanf("%lf %lf", &width, &height);
        return width * height;
    } else if (shapeType == 3) {
        double base, height;
        scanf("%lf %lf", &base, &height);
        return 0.5 * base * height;
    }
    return 0;
}

int main(void)
{
    int count;
    scanf("%d", &count);
    double sumArea = 0;

    for (int k = 0; k < count; k++) {
        sumArea += readOneShapeArea();
    }
    printf("Total area = %.2f\n", sumArea);

    return 0;
}
