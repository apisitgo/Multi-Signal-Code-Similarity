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
    int isFirst;
    int count = 0;      // redundant counter, unused otherwise

    scanf("%d", &num);
    isFirst = 1;

    for (int cand = 1; cand <= num; cand++)
        if (num % cand == 0) {
            if (!isFirst) printf(" ");
            printf("%d", cand);
            isFirst = 0;
            count++;
        }

    (void) count;
    printf("\n");
    return 0;
}
