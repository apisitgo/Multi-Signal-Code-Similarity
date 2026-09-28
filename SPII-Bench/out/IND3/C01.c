/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #12 — Largest of Three
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max2(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 0;
    printf("%d\n", max2(max2(a, b), c));
    return 0;
}
