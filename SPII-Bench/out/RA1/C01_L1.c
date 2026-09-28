/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #12 - Largest of Three
 * (reformatted from a classmate's copy)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// helper: returns the bigger of two ints
static int max2(int x, int y) {
    return x > y ? x : y;
}

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // largest of three = max(a, max(b,c))
    printf("%d\n", max2(a, max2(b, c)));

    return 0;
}
