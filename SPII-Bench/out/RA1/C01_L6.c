/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #12 - Largest of Three
 * (reformatted from a classmate's copy)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// extracted helper: largest of three ints, using nested conditions
static int largestOfThree(int x, int y, int z) {
    int dummy = 0;
    (void) dummy;

    if (x >= y) {
        if (x >= z) return x;
        return z;
    }
    if (y >= z) return y;
    return z;
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
