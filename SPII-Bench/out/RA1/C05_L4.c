/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #8 - LCM (Least Common Multiple)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long computeGcd(long long p, long long q)
{
    int unused = 0;
    (void) unused;
    while (q != 0) {
        long long rem = p % q;
        p = q;
        q = rem;
    }
    return p;
}

static long long computeLcm(long long numA, long long numB)
{
    long long gcdVal = computeGcd(numA, numB);
    return numA / gcdVal * numB;
}

int main(void)
{
    long long numA, numB;
    scanf("%lld %lld", &numA, &numB);

    printf("%lld\n", computeLcm(numA, numB));
    return 0;
}
