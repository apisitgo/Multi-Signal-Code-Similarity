#include <stdio.h>
#include <stdlib.h>

static const double CIRCLE_CONSTANT = 3.14159265358979323846;

static double circle_area(double radius_value)
{
    return CIRCLE_CONSTANT * radius_value * radius_value;
}

static double rectangle_area(double width_value, double height_value)
{
    return width_value * height_value;
}

static double triangle_area(double base_value, double height_value)
{
    return 0.5 * base_value * height_value;
}

int main(void)
{
    int shape_choice;
    scanf("%d", &shape_choice);

    if (shape_choice == 1) {
        double radius_value;
        scanf("%lf", &radius_value);
        printf("Area = %.2f\n", circle_area(radius_value));
    } else if (shape_choice == 2) {
        double width_value, height_value;
        scanf("%lf %lf", &width_value, &height_value);
        printf("Area = %.2f\n", rectangle_area(width_value, height_value));
    } else if (shape_choice == 3) {
        double base_value, height_value;
        scanf("%lf %lf", &base_value, &height_value);
        printf("Area = %.2f\n", triangle_area(base_value, height_value));
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
