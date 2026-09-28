/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #8 - LCM (Least Common Multiple)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long computeGcd(long long p, long long q)
{
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
    long long result = numA / gcdVal;
    result = result * numB;
    return result;
}

int main(void)
{
    long long numA = 0, numB = 0;
    long long ans;

    scanf("%lld", &numA);
    scanf("%lld", &numB);

    ans = computeLcm(numA, numB);
    printf("%lld\n", ans);
    return 0;
}
