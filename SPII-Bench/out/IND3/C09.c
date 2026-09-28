/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Loops and Patterns #3 — Star Pyramid
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rep(char c, int k)
{
    for (int i = 0; i < k; i++) putchar(c);
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 1; i <= n; i++) {
        rep(' ', n - i);
        rep('*', 2 * i - 1);
        putchar('\n');
    }
    return 0;
}
