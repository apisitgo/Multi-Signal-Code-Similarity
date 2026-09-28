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
    int cand = 1;
    while (cand <= num) {
        if (num % cand == 0) {
            if (!isFirst) printf(" ");
            printf("%d", cand);
            isFirst = 0;
        }
        cand += 1;
    }
    printf("\n");
}

int main(void)
{
    int num;
    scanf("%d", &num);
    printDivisors(num);
    return 0;
}
