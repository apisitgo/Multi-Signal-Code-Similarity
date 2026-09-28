/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #2 — Shape Menu
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

double area(int t, int *ok)
{
    double x, y;
    *ok = 1;
    if (t == 1) {
        if (scanf("%lf", &x) != 1) { *ok = 0; return 0; }
        return PI * x * x;
    }
    if (t == 2 || t == 3) {
        if (scanf("%lf %lf", &x, &y) != 2) { *ok = 0; return 0; }
        return t == 2 ? x * y : 0.5 * x * y;
    }
    *ok = 0;
    return 0;
}

int main(void)
{
    int t, ok;
    if (scanf("%d", &t) != 1) return 0;
    double a = area(t, &ok);
    if (!ok) printf("Invalid choice\n");
    else printf("Area = %.2f\n", a);
    return 0;
}
