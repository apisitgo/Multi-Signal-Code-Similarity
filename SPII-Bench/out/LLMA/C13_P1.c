#include <stdio.h>

#define PI_VAL 3.14159265358979323846

int main(void) {
    int n;
    scanf("%d", &n);
    double sum = 0;
    for (int k = 0; k < n; k++) {
        int shape;
        scanf("%d", &shape);
        if (shape == 1) {
            double r;
            scanf("%lf", &r);
            sum += PI_VAL * r * r;
        } else if (shape == 2) {
            double w, h;
            scanf("%lf %lf", &w, &h);
            sum += w * h;
        } else if (shape == 3) {
            double b, h;
            scanf("%lf %lf", &b, &h);
            sum += 0.5 * b * h;
        }
    }
    printf("Total area = %.2f\n", sum);
    return 0;
}
