/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #3 — Total Area
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

int main(void)
{
    int n;
    scanf("%d", &n);
    double total = 0;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            double r;
            scanf("%lf", &r);
            total += PI * r * r;
        } else if (t == 2) {
            double w, h;
            scanf("%lf %lf", &w, &h);
            total += w * h;
        } else if (t == 3) {
            double b, h;
            scanf("%lf %lf", &b, &h);
            total += 0.5 * b * h;
        }
    }
    printf("Total area = %.2f\n", total);

    return 0;
}
