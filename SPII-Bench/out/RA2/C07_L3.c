/* Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 - Fibonacci Series
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int terms, k, last;
    long long cur, nxt, tmp;

    scanf("%d", &terms);

    // cur = current term, nxt = next term
    cur = 0;
    nxt = 1;
    last = terms - 1;

    for (k = 0; k < terms; k++) {
        printf("%lld", cur);
        if (k < last)
            printf(" ");   // separator between terms

        tmp = cur + nxt;
        cur = nxt;
        nxt = tmp;
    }
    printf("\n");

    return 0;
}
