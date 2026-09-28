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
    int n;
        scanf("%d", &n);
        double total_area = 0;
        for (int i = 0; i < n; i++) {
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                double r;
                scanf("%lf", &r);
                total_area += 3.14159 * r * r;
            } else if (choice == 2) {
                int w, h;
                scanf("%d %d", &w, &h);
                total_area += w * h;
            } else if (choice == 3) {
                double base, height;
                scanf("%lf %lf", &base, &height);
                total_area += 0.5 * base * height;
            }
        }
        printf("Total area = %.2f\n", total_area);


    return 0;
}
