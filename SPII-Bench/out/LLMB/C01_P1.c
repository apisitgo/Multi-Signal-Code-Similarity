/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static int largest_of_three(int p, int q, int r)
{
    int best = p;
    if (q > best) best = q;
    if (r > best) best = r;
    return best;
}

int main(void)
{
    int p, q, r;
    if (scanf("%d %d %d", &p, &q, &r) != 3) return 0;
    printf("%d\n", largest_of_three(p, q, r));
    return 0;
}
