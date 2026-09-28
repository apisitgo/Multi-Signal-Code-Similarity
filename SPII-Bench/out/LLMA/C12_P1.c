#include <stdio.h>

#define PI_VAL 3.14159265358979323846

int main(void) {
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            double r;
            scanf("%lf", &r);
            printf("Area = %.2f\n", PI_VAL * r * r);
            break;
        }
        case 2: {
            double w, h;
            scanf("%lf %lf", &w, &h);
            printf("Area = %.2f\n", w * h);
            break;
        }
        case 3: {
            double b, h;
            scanf("%lf %lf", &b, &h);
            printf("Area = %.2f\n", 0.5 * b * h);
            break;
        }
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
