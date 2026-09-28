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
    int choice;
    double area = 0;
    int valid = 1;

    scanf("%d", &choice);

    if (choice == 1) {
        double radius;
        scanf("%lf", &radius);
        area = PI * radius * radius;
    } else if (choice == 2) {
        double width, height;
        scanf("%lf %lf", &width, &height);
        area = width * height;
    } else if (choice == 3) {
        double base, height;
        scanf("%lf %lf", &base, &height);
        area = 0.5 * base * height;
    } else {
        valid = 0;
    }

    if (valid) printf("Area = %.2f\n", area);
    else printf("Invalid choice\n");

    return 0;
}
