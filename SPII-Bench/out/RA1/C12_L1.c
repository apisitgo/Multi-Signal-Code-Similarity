/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Geometry Area #2 - Shape Menu
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

int main(void)
{
    int c;
    scanf("%d", &c);

    // 1 = circle, 2 = rectangle, 3 = triangle
    if (c == 1) {
        double r;
        scanf("%lf", &r);
        printf("Area = %.2f\n", PI * r * r);
    } else if (c == 2) {
        double w, h;
        scanf("%lf %lf", &w, &h);
        printf("Area = %.2f\n", w * h);
    } else if (c == 3) {
        double b, h;
        scanf("%lf %lf", &b, &h);
        printf("Area = %.2f\n", 0.5 * b * h);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
