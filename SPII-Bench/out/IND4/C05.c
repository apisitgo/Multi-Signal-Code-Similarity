/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #8 — LCM (Least Common Multiple)
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", (long long)a * b / gcd(a, b));

    return 0;
}
