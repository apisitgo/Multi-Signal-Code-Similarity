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
    double sumArea;
    int shapesSeen = 0;      // redundant counter

    scanf("%d", &count);
    sumArea = 0;

    for (int k = 0; k < count; k++) {
        int shapeType;
        scanf("%d", &shapeType);
        shapesSeen++;
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
    (void) shapesSeen;
    printf("Total area = %.2f\n", sumArea);

    return 0;
}
