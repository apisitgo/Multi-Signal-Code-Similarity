/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Geometry Area #3 - Total Area
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

int main(void)
{
    int count;
    scanf("%d", &count);
    double sumArea = 0;

    // shapeType=1 circle, 2 rectangle, 3 triangle
    for (int k = 0; k < count; k++) {
        int shapeType;
        scanf("%d", &shapeType);
        if (shapeType == 1) {
            double radius;
            scanf("%lf", &radius);
            sumArea += PI * radius * radius;
        } else if (shapeType == 2) {
            double width, height;
            scanf("%lf %lf", &width, &height);
            sumArea += width * height;
        } else if (shapeType == 3) {
            double base, height;
            scanf("%lf %lf", &base, &height);
            sumArea += 0.5 * base * height;
        }
    }
    printf("Total area = %.2f\n", sumArea);

    return 0;
}
