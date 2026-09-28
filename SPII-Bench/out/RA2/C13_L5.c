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
        scanf("%lf", &x);
        scanf("%lf", &y);
        return x * y;
    }
    else if (kind == 3)
    {
        scanf("%lf", &x);
        scanf("%lf", &y);
        return 0.5 * x * y;
    }
    *valid = 0;
    return 0.0;
}

static double total_area(int shapes)
{
    int kind, valid;
    double sumArea = 0.0, piece;
    while (shapes-- > 0)
    {
        scanf("%d", &kind);
        piece = one_shape(kind, &valid);
        if (valid)
            sumArea = sumArea + piece;
    }
    return sumArea;
}

int main(void)
{
    int shapes;
    double result;
    scanf("%d", &shapes);
    result = total_area(shapes);
    fputs("Total area = ", stdout);
    printf("%.2f\n", result);
    return 0;
}
