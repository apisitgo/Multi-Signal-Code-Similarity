/* Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 - Fibonacci Series
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int terms;
    scanf("%d", &terms);

    // cur = current term, nxt = next term
    long long cur = 0, nxt = 1;

    for (int k = 0; k < terms; k++) {
        printf("%lld", cur);
        if (k < terms - 1)
            printf(" ");   // separator between terms

        long long tmp = cur + nxt;
        cur = nxt;
        nxt = tmp;
    }
    printf("\n");

    return 0;
}
