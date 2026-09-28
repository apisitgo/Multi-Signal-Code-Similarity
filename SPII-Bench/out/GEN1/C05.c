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
        int orig_a = a, orig_b = b;
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        printf("%d\n", (orig_a / a) * orig_b);


    return 0;
}
