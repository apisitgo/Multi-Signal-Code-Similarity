/* ============================================================
 *  Programming Fundamentals - Lab exercise
 *  Task    : Geometry Area #3 - Total Area
 *  Student : <student id> <full name>
 * ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const double PI_VAL = 3.14159265358979323846;

/* read the dimensions of one shape; *valid is 0 for unknown kinds */
static double one_shape(int kind, int *valid)
{
    double x, y;
    *valid = 1;
    if (kind == 1)
    {
        scanf("%lf", &x);
        return PI_VAL * x * x;
    }
    else if (kind == 2)
    {
        scanf("%lf %lf", &x, &y);
        return x * y;
    }
    else if (kind == 3)
    {
        scanf("%lf %lf", &x, &y);
        return 0.5 * x * y;
    }
    *valid = 0;
    return 0.0;
}

static double total_area(int shapes)
{
    int k, kind, valid;
    double sumArea = 0.0, piece;
    for (k = 0; k < shapes; k++)
    {
        scanf("%d", &kind);
        piece = one_shape(kind, &valid);
        if (valid)
            sumArea += piece;
    }
    return sumArea;
}

int main(void)
{
    int shapes;
    scanf("%d", &shapes);
    printf("Total area = %.2f\n", total_area(shapes));
    return 0;
}
