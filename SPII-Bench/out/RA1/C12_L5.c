/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Geometry Area #2 - Shape Menu
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

static double circleArea(double radius)
{
    return PI * radius * radius;
}

static double rectArea(double width, double height)
{
    return width * height;
}

static double triArea(double base, double height)
{
    double half = base * 0.5;
    return half * height;
}

int main(void)
{
    int choice;
    double area = 0;
    int valid = 1;

    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            double radius;
            scanf("%lf", &radius);
            area = circleArea(radius);
            break;
        }
        case 2: {
            double width, height;
            scanf("%lf %lf", &width, &height);
            area = rectArea(width, height);
            break;
        }
        case 3: {
            double base, height;
            scanf("%lf %lf", &base, &height);
            area = triArea(base, height);
            break;
        }
        default:
            valid = 0;
    }

    if (valid) {
        printf("Area = %.2f\n", area);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
