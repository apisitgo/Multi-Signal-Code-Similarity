/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #27 - Fibonacci Series
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void printFibonacci(int count)
{
    long long prev = 0, curr = 1;
    for (int k = 0; k < count; k++) {
        printf("%lld", prev);
        if (k < count - 1) printf(" ");
        long long nxt = prev + curr;
        prev = curr;
        curr = nxt;
    }
    printf("\n");
}

int main(void)
{
    int count;
    scanf("%d", &count);
    printFibonacci(count);
    return 0;
}
