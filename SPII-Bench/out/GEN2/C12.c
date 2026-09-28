/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #2 — Shape Menu
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const double PI = 3.14159265358979323846;
    int choice;
    if (scanf("%d", &choice) != 1) return 1;

    double area;
    if (choice == 1) {
        double r;
        if (scanf("%lf", &r) != 1) return 1;
        area = PI * r * r;
    } else if (choice == 2) {
        double w, h;
        if (scanf("%lf %lf", &w, &h) != 2) return 1;
        area = w * h;
    } else if (choice == 3) {
        double base, height;
        if (scanf("%lf %lf", &base, &height) != 2) return 1;
        area = 0.5 * base * height;
    } else {
        printf("Invalid choice\n");
        return 0;
    }
    printf("Area = %.2f\n", area);

    return 0;
}
