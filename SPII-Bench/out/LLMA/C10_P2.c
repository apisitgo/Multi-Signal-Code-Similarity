#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void format_number(double number_value, char *destination_buffer)
{
    if (!isinf(number_value) && number_value == floor(number_value)) {
        sprintf(destination_buffer, "%lld", (long long) number_value);
    } else {
        sprintf(destination_buffer, "%.2f", number_value);
    }
}

static double rectangle_area(double width_value, double height_value)
{
    return width_value * height_value;
}

static double rectangle_perimeter(double width_value, double height_value)
{
    return 2 * (width_value + height_value);
}

int main(void)
{
    double width_value = 0;
    double height_value = 0;

    scanf("%lf", &width_value);
    scanf("%lf", &height_value);

    char area_text[64];
    char perimeter_text[64];

    format_number(rectangle_area(width_value, height_value), area_text);
    format_number(rectangle_perimeter(width_value, height_value), perimeter_text);

    printf("Area = %s\n", area_text);
    printf("Perimeter = %s\n", perimeter_text);

    return 0;
}
