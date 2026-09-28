/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #12 - Largest of Three
 * (reformatted from a classmate's copy)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// helper: returns the bigger of two ints
static int biggerOf(int p, int q) {
    return p > q ? p : q;
}

int main(void) {
    int num1;
    int num2, num3;
    int dummy = 0;      // unused redundant variable
    scanf("%d %d %d", &num1, &num2, &num3);

    int best = biggerOf(num2, num3);
    // largest of three = max(a, max(b,c))
    printf("%d\n", biggerOf(num1, best));

    (void) dummy;
    return 0;
}
