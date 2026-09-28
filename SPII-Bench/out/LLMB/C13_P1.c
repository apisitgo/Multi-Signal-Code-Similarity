/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static const double PI_VALUE = 3.14159265358979323846;

static double read_shape_area(int kind)
{
    double p, q;
    switch (kind) {
    case 1:
        scanf("%lf", &p);
        return PI_VALUE * p * p;
    case 2:
        scanf("%lf %lf", &p, &q);
        return p * q;
    case 3:
        scanf("%lf %lf", &p, &q);
        return p * q / 2.0;
    default:
        return 0.0;
    }
}

int main(void)
{
    int count;
    double sum = 0.0;
    if (scanf("%d", &count) != 1) return 0;
    for (int k = 0; k < count; k++) {
        int kind;
        scanf("%d", &kind);
        sum += read_shape_area(kind);
    }
    printf("Total area = %.2f\n", sum);
    return 0;
}
