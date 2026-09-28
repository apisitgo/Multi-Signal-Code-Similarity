/* Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 - Fibonacci Series
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print the remaining terms recursively, pair (cur, nxt) carried along
static void print_series(int k, int terms, long long cur, long long nxt) {
    if (k >= terms) {
        putchar('\n');
        return;
    }
    printf(k == 0 ? "%lld" : " %lld", cur);
    print_series(k + 1, terms, nxt, cur + nxt);
}

int main(void) {
    int terms;
    scanf("%d", &terms);
    print_series(0, terms, 0, 1);
    return 0;
}
