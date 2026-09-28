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

static int computeArea(int choice, double *outArea)
{
    switch (choice) {
        case 1: {
            double radius;
            scanf("%lf", &radius);
            *outArea = circleArea(radius);
            return 1;
        }
        case 2: {
            double width, height;
            scanf("%lf %lf", &width, &height);
            *outArea = rectArea(width, height);
            return 1;
        }
        case 3: {
            double base, height;
            scanf("%lf %lf", &base, &height);
            *outArea = triArea(base, height);
            return 1;
        }
        default:
            return 0;
    }
}

int main(void)
{
    int choice;
    double area = 0;

    scanf("%d", &choice);

    if (!computeArea(choice, &area)) {
        printf("Invalid choice\n");
        return 0;
    }
    printf("Area = %.2f\n", area);

    return 0;
}
