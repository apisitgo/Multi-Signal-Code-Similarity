/* Area of a chosen shape: 1 circle, 2 rectangle, 3 triangle. */
#include <stdio.h>

static const double CIRCLE_CONST = 3.14159265358979323846;

int main(void)
{
    int shape;
    double p = 0, q = 0, area;

    scanf("%d", &shape);
    switch (shape) {
    case 1:
        scanf("%lf", &p);
        area = CIRCLE_CONST * p * p;
        break;
    case 2:
        scanf("%lf %lf", &p, &q);
        area = p * q;
        break;
    case 3:
        scanf("%lf %lf", &p, &q);
        area = p * q / 2.0;
        break;
    default:
        puts("Invalid choice");
        return 0;
    }
    printf("Area = %.2f\n", area);
    return 0;
}
