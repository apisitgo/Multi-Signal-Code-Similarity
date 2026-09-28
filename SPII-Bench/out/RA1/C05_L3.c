/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #8 - LCM (Least Common Multiple)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long numA, numB;
    long long gcdVal;
    int unused = 0;

    scanf("%lld %lld", &numA, &numB);

    long long p = numA, q = numB;
    while (q != 0) {
        long long rem = p % q;
        p = q;
        q = rem;
    }
    gcdVal = p;

    (void) unused;
    printf("%lld\n", numA / gcdVal * numB);
    return 0;
}
