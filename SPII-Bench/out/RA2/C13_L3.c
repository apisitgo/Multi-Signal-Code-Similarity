/* ============================================================
 *  Programming Fundamentals - Lab exercise
 *  Task    : Geometry Area #3 - Total Area
 *  Student : <student id> <full name>
 * ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const double PI_VAL = 3.14159265358979323846;

int main(void)
{
    int shapes, k, kind;
    double sumArea, x, y, piece;

    scanf("%d", &shapes);
    sumArea = 0.0;   /* running sum of all areas */

    for (k = 0; k < shapes; k++)
    {
        scanf("%d", &kind);   /* shape type */
        piece = 0.0;

        if (kind == 1)
        {
            /* circle: x = radius */
            scanf("%lf", &x);
            piece = PI_VAL * x * x;
            sumArea += piece;
        }
        else if (kind == 2)
        {
            /* rectangle: x = width, y = height */
            scanf("%lf %lf", &x, &y);
            piece = x * y;
            sumArea += piece;
        }
        else if (kind == 3)
        {
            /* triangle: x = base, y = height */
            scanf("%lf %lf", &x, &y);
            piece = 0.5 * x * y;
            sumArea += piece;
        }
    }

    printf("Total area = %.2f\n", sumArea);
    return 0;
}
