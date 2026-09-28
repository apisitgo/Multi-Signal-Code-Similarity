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
    scanf("%d", &choice);

    // 1 = circle, 2 = rectangle, 3 = triangle
    if (choice == 1) {
        double radius;
        scanf("%lf", &radius);
        printf("Area = %.2f\n", PI * radius * radius);
    } else if (choice == 2) {
        double width, height;
        scanf("%lf %lf", &width, &height);
        printf("Area = %.2f\n", width * height);
    } else if (choice == 3) {
        double base, height;
        scanf("%lf %lf", &base, &height);
        printf("Area = %.2f\n", 0.5 * base * height);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
