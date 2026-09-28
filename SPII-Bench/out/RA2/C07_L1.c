/* Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 - Fibonacci Series
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    // a = current term, b = next term
    long long a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        printf("%lld", a);
        if (i < n - 1)
            printf(" ");   // separator between terms

        long long t = a + b;
        a = b;
        b = t;
    }
    printf("\n");

    return 0;
}
