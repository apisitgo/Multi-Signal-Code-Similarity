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
    int a, b, c, res;
    scanf("%d %d %d", &a, &b, &c);
    res = a;
    if (b > res) res = b;
    if (c > res) res = c;
    printf("%d\n", res);

    return 0;
}
