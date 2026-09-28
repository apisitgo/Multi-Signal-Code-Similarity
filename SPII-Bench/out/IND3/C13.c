/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #3 — Total Area
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

double area(int t)
{
    double x, y;
    if (t == 1) {
        if (scanf("%lf", &x) != 1) return 0;
        return PI * x * x;
    }
    if (t == 2 || t == 3) {
        if (scanf("%lf %lf", &x, &y) != 2) return 0;
        return t == 2 ? x * y : 0.5 * x * y;
    }
    return 0;
}

int main(void)
{
    int n, t;
    double tot = 0;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &t) != 1) break;
        tot += area(t);
    }
    printf("Total area = %.2f\n", tot);
    return 0;
}
