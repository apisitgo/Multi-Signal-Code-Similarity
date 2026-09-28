/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #30 - Divisors of a Number
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void printDivisors(int num)
{
    int isFirst = 1;
    int count = 0;

    for (int cand = 1; cand <= num; cand++)
        if (num % cand == 0) {
            if (!isFirst) printf(" ");
            printf("%d", cand);
            isFirst = 0;
            count++;
        }

    (void) count;
    printf("\n");
}

int main(void)
{
    int num;
    scanf("%d", &num);
    printDivisors(num);
    return 0;
}
