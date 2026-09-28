/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #1 — Rectangle
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int width, height;
        scanf("%d %d", &width, &height);
        int area = width * height;
        int perimeter = 2 * (width + height);
        printf("Area = %d\n", area);
        printf("Perimeter = %d\n", perimeter);


    return 0;
}
