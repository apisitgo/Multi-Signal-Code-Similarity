/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #3 — Total Area
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const double PI = 3.14159265358979323846;
    int n;
    if (scanf("%d", &n) != 1) return 1;

    double total = 0.0;
    for (int i = 0; i < n; i++) {
        int type;
        if (scanf("%d", &type) != 1) return 1;
        if (type == 1) {
            double r;
            if (scanf("%lf", &r) != 1) return 1;
            total += PI * r * r;
        } else if (type == 2) {
            double w, h;
            if (scanf("%lf %lf", &w, &h) != 2) return 1;
            total += w * h;
        } else if (type == 3) {
            double base, height;
            if (scanf("%lf %lf", &base, &height) != 2) return 1;
            total += 0.5 * base * height;
        }
    }
    printf("Total area = %.2f\n", total);

    return 0;
}
