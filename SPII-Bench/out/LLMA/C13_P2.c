#include <stdio.h>
#include <stdlib.h>

static const double CIRCLE_CONSTANT = 3.14159265358979323846;

static double area_for_shape(int shape_code)
{
    if (shape_code == 1) {
        double radius_value;
        scanf("%lf", &radius_value);
        return CIRCLE_CONSTANT * radius_value * radius_value;
    } else if (shape_code == 2) {
        double width_value, height_value;
        scanf("%lf %lf", &width_value, &height_value);
        return width_value * height_value;
    } else if (shape_code == 3) {
        double base_value, height_value;
        scanf("%lf %lf", &base_value, &height_value);
        return 0.5 * base_value * height_value;
    }
    return 0.0;
}

int main(void)
{
    int shape_count;
    scanf("%d", &shape_count);

    double total_area = 0.0;
    for (int index = 0; index < shape_count; index++) {
        int shape_code;
        scanf("%d", &shape_code);
        total_area += area_for_shape(shape_code);
    }

    printf("Total area = %.2f\n", total_area);

    return 0;
}
