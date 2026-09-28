/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static void print_fibonacci(int terms)
{
    long long prev = 0, cur = 1;
    for (int k = 0; k < terms; k++) {
        if (k > 0) putchar(' ');
        printf("%lld", prev);
        long long next = prev + cur;
        prev = cur;
        cur = next;
    }
    putchar('\n');
}

int main(void)
{
    int terms;
    if (scanf("%d", &terms) != 1) return 0;
    print_fibonacci(terms);
    return 0;
}
