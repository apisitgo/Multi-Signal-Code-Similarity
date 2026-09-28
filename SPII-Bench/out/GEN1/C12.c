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
    int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            double r;
            scanf("%lf", &r);
            printf("Area = %.2f\n", 3.14159 * r * r);
        } else if (choice == 2) {
            int w, h;
            scanf("%d %d", &w, &h);
            printf("Area = %.2f\n", (double)(w * h));
        } else if (choice == 3) {
            double base, height;
            scanf("%lf %lf", &base, &height);
            printf("Area = %.2f\n", 0.5 * base * height);
        }


    return 0;
}
