/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #3 — Total Area
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    int n;
    printf("Enter number of shapes: ");
    scanf("%d", &n);

    double total = 0.0;
    int i = 0;
    while (i < n) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            double r;
            scanf("%lf", &r);
            total = total + PI * r * r;
        } else if (type == 2) {
            double w, h;
            scanf("%lf %lf", &w, &h);
            total = total + w * h;
        } else if (type == 3) {
            double base, height;
            scanf("%lf %lf", &base, &height);
            total = total + 0.5 * base * height;
        }

        i = i + 1;
    }

    printf("Total area = %.2f\n", total);

    return 0;
}
