/* ============================================================
 *  Programming Fundamentals - Lab exercise
 *  Task    : Geometry Area #3 - Total Area
 *  Student : <student id> <full name>
 * ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI_VAL 3.14159265358979323846

int main(void)
{
    int shapes;
    scanf("%d", &shapes);

    double sumArea = 0;   /* running sum of all areas */

    for (int k = 0; k < shapes; k++)
    {
        int kind;
        scanf("%d", &kind);   /* shape type */

        if (kind == 1)
        {
            /* circle */
            double rad;
            scanf("%lf", &rad);
            sumArea += PI_VAL * rad * rad;
        }
        else if (kind == 2)
        {
            /* rectangle */
            double wd, ht;
            scanf("%lf %lf", &wd, &ht);
            sumArea += wd * ht;
        }
        else if (kind == 3)
        {
            /* triangle */
            double bs, ht;
            scanf("%lf %lf", &bs, &ht);
            sumArea += 0.5 * bs * ht;
        }
    }

    printf("Total area = %.2f\n", sumArea);
    return 0;
}
