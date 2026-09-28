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
    int c;
    double a, b, res = 0;
    scanf("%d", &c);
    if (c == 1) {
        scanf("%lf", &a);
        res = 3.14159265358979 * a * a;
    } else if (c == 2) {
        scanf("%lf %lf", &a, &b);
        res = a * b;
    } else if (c == 3) {
        scanf("%lf %lf", &a, &b);
        res = 0.5 * a * b;
    }
    printf("Area = %.2f\n", res);

    return 0;
}
