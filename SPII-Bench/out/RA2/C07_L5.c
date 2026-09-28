/* Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 - Fibonacci Series
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// move the pair one step forward in the sequence
static void advance(long long *cur, long long *nxt) {
    *nxt = *cur + *nxt;
    *cur = *nxt - *cur;
}

static void print_series(int terms) {
    int k = 0;
    long long cur = 0, nxt = 1;

    while (k < terms) {
        if (k > 0)
            putchar(' ');
        printf("%lld", cur);
        advance(&cur, &nxt);
        k += 1;
    }
    putchar('\n');
}

int main(void) {
    int terms;
    scanf("%d", &terms);
    print_series(terms);
    return 0;
}
