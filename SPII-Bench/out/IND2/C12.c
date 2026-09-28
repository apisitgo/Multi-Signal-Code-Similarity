/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #2 — Shape Menu
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    int choice;
    printf("1 = Circle, 2 = Rectangle, 3 = Triangle\n");
    printf("Choose shape: ");
    scanf("%d", &choice);

    double area = 0.0;

    if (choice == 1) {
        double r;
        scanf("%lf", &r);
        area = PI * r * r;
    } else if (choice == 2) {
        double w, h;
        scanf("%lf %lf", &w, &h);
        area = w * h;
    } else if (choice == 3) {
        double base, height;
        scanf("%lf %lf", &base, &height);
        area = 0.5 * base * height;
    }

    printf("Area = %.2f\n", area);

    return 0;
}
