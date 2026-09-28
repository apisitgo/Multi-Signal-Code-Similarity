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
    double x, y, res = 0.0;
    *valid = 1;
    switch (kind)
    {
    case 1:
        scanf("%lf", &x);
        res = PI_VAL * x * x;
        break;
    case 2:
        scanf("%lf", &x);
        scanf("%lf", &y);
        res = x * y;
        break;
    case 3:
        scanf("%lf", &x);
        scanf("%lf", &y);
        res = 0.5 * x * y;
        break;
    default:
        *valid = 0;
    }
    return res;
}

/* add up `left` shapes recursively, keeping the same summation order */
static double total_area(int left, double acc)
{
    int kind, valid;
    double piece;
    if (left <= 0)
        return acc;
    scanf("%d", &kind);
    piece = one_shape(kind, &valid);
    if (!valid)
        return total_area(left - 1, acc);
    return total_area(left - 1, acc + piece);
}

int main(void)
{
    int shapes;
    double result;
    scanf("%d", &shapes);
    result = total_area(shapes, 0.0);
    fputs("Total area = ", stdout);
    printf("%.2f\n", result);
    return 0;
}
