/* Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 - Fibonacci Series
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// move the pair one step forward in the sequence
static void advance(long long *cur, long long *nxt) {
    long long tmp = *cur + *nxt;
    *cur = *nxt;
    *nxt = tmp;
}

static void print_series(int terms) {
    int k, last = terms - 1;
    long long cur = 0, nxt = 1;

    for (k = 0; k < terms; k++) {
        printf("%lld", cur);
        if (k < last)
            printf(" ");
        advance(&cur, &nxt);
    }
    printf("\n");
}

int main(void) {
    int terms;
    scanf("%d", &terms);
    print_series(terms);
    return 0;
}
