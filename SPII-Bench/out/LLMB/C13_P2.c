/* Accumulates the total area over a list of shapes. */
#include <stdio.h>

static const double CIRCLE_CONST = 3.14159265358979323846;

static double shape_area(int kind)
{
    double x, y;
    switch (kind) {
    case 1:
        scanf("%lf", &x);
        return CIRCLE_CONST * x * x;
    case 2:
        scanf("%lf %lf", &x, &y);
        return x * y;
    case 3:
        scanf("%lf %lf", &x, &y);
        return x * y / 2.0;
    default:
        return 0.0;
    }
}

int main(void)
{
    int count, kind;
    double sum = 0.0;

    scanf("%d", &count);
    while (count-- > 0) {
        scanf("%d", &kind);
        sum += shape_area(kind);
    }
    printf("Total area = %.2f\n", sum);
    return 0;
}
