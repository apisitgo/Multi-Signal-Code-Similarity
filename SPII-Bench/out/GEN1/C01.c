/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #12 — Largest of Three
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        printf("%d\n", max);


    return 0;
}
