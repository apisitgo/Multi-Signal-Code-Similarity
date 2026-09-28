// area calculator
// 1 = circle, 2 = rectangle, 3 = triangle
#include <stdio.h>

int main(void)
{
    int choice;
    double r, w, h, b, area;
    double pi = 3.14159265358979323846;

    scanf("%d", &choice);

    if (choice == 1) {
        scanf("%lf", &r);
        area = pi * r * r;
        printf("Area = %.2f\n", area);
    }
    else if (choice == 2) {
        scanf("%lf", &w);
        scanf("%lf", &h);
        area = w * h;
        printf("Area = %.2f\n", area);
    }
    else if (choice == 3) {
        scanf("%lf", &b);
        scanf("%lf", &h);
        area = (b * h) / 2;
        printf("Area = %.2f\n", area);
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}
