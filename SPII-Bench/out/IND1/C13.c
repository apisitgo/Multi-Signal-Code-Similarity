/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #3 — Total Area
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265359

int main(void)
{
    int n;
    scanf("%d", &n);

    double total_area = 0;

    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            // Circle
            double r;
            scanf("%lf", &r);
            total_area = total_area + (PI * r * r);
        } else if (type == 2) {
            // Rectangle
            double w, h;
            scanf("%lf %lf", &w, &h);
            total_area = total_area + (w * h);
        } else if (type == 3) {
            // Triangle
            double base, height;
            scanf("%lf %lf", &base, &height);
            total_area = total_area + (0.5 * base * height);
        }
    }

    printf("Total area = %.2f\n", total_area);

    return 0;
}
