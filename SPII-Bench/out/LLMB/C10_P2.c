/* Rectangle area and perimeter. */
#include <stdio.h>
#include <math.h>

static void print_number(const char *label, double x)
{
    if (isinf(x) || x != floor(x))
        printf("%s = %.2f\n", label, x);
    else
        printf("%s = %lld\n", label, (long long) x);
}

int main(void)
{
    double width = 0, height = 0;
    scanf("%lf %lf", &width, &height);
    print_number("Area", width * height);
    print_number("Perimeter", 2 * (width + height));
    return 0;
}
