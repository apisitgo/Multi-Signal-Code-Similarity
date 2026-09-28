/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #8 — LCM (Least Common Multiple)
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    // Calculate GCD using Euclid's algorithm
    int temp_a = a;
    int temp_b = b;
    while (temp_b != 0) {
        int temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    int gcd = temp_a;

    // Calculate LCM = a * b / gcd
    int lcm = (a * b) / gcd;

    printf("%d\n", lcm);

    return 0;
}
