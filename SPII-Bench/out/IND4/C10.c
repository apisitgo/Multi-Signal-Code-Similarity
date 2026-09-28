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
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Area = %d\n", a * b);
    printf("Perimeter = %d\n", 2 * (a + b));

    return 0;
}
