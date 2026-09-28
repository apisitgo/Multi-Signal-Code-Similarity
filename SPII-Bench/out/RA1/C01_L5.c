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

// extracted helper: largest of three ints
static int largestOfThree(int x, int y, int z) {
    int dummy = 0;
    int best = biggerOf(y, z);
    (void) dummy;
    return biggerOf(x, best);
}

int main(void) {
    int num1, num2, num3;
    int result;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    result = largestOfThree(num1, num2, num3);
    printf("%d\n", result);

    return 0;
}
