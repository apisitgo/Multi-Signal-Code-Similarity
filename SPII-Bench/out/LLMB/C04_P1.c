/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static void print_divisors(int value)
{
    const char *sep = "";
    for (int d = 1; d <= value; d++) {
        if (value % d != 0) continue;
        printf("%s%d", sep, d);
        sep = " ";
    }
    putchar('\n');
}

int main(void)
{
    int value;
    if (scanf("%d", &value) != 1) return 0;
    print_divisors(value);
    return 0;
}
