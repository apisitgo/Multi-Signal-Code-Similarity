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
    scanf("%lld %lld", &numA, &numB);

    // Euclid's algorithm to get gcd(numA,numB), then lcm = numA/gcd*numB
    long long p = numA, q = numB;
    while (q != 0) {
        long long rem = p % q;
        p = q;
        q = rem;
    }

    printf("%lld\n", numA / p * numB);
    return 0;
}
