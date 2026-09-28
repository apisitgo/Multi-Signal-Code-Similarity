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

    switch (shapeType) {
        case 1: {
            double radius;
            scanf("%lf", &radius);
            return PI * radius * radius;
        }
        case 2: {
            double width, height;
            scanf("%lf %lf", &width, &height);
            return width * height;
        }
        case 3: {
            double base, height;
            scanf("%lf %lf", &base, &height);
            double half = base * 0.5;
            return half * height;
        }
        default:
            return 0;
    }
}

/* recursive accumulation instead of the loop */
static double sumShapeAreas(int remaining)
{
    if (remaining <= 0) return 0;
    double thisArea = readOneShapeArea();
    return thisArea + sumShapeAreas(remaining - 1);
}

int main(void)
{
    int count;
    scanf("%d", &count);

    double sumArea = sumShapeAreas(count);
    printf("Total area = %.2f\n", sumArea);

    return 0;
}
