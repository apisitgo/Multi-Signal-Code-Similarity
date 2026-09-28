/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static const double PI_VALUE = 3.14159265358979323846;

static double circle_area(double radius) { return PI_VALUE * radius * radius; }
static double rect_area(double w, double h) { return w * h; }
static double triangle_area(double base, double h) { return base * h / 2.0; }

int main(void)
{
    int shape;
    double p, q;
    if (scanf("%d", &shape) != 1) return 0;

    switch (shape) {
    case 1:
        scanf("%lf", &p);
        printf("Area = %.2f\n", circle_area(p));
        break;
    case 2:
        scanf("%lf %lf", &p, &q);
        printf("Area = %.2f\n", rect_area(p, q));
        break;
    case 3:
        scanf("%lf %lf", &p, &q);
        printf("Area = %.2f\n", triangle_area(p, q));
        break;
    default:
        printf("Invalid choice\n");
    }
    return 0;
}
