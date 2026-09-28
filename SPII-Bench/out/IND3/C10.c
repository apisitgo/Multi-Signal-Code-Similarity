/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #1 — Rectangle
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

void pnum(const char *lbl, double x)
{
    if (x == floor(x) && fabs(x) < 1e15) printf("%s = %.0f\n", lbl, x);
    else printf("%s = %.2f\n", lbl, x);
}

int main(void)
{
    double w, h;
    if (scanf("%lf %lf", &w, &h) != 2) return 0;
    pnum("Area", w * h);
    pnum("Perimeter", 2 * (w + h));
    return 0;
}
