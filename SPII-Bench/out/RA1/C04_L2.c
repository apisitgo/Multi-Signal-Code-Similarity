/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #30 - Divisors of a Number
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int num;
    scanf("%d", &num);

    int isFirst = 1;
    // print every candidate from 1..num that divides num exactly
    for (int cand = 1; cand <= num; cand++)
        if (num % cand == 0) {
            if (!isFirst) printf(" ");
            printf("%d", cand);
            isFirst = 0;
        }

    printf("\n");
    return 0;
}
