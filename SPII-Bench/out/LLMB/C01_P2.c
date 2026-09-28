/* Largest of three integers, chosen by a running comparison. */
#include <stdio.h>

int main(void)
{
    int values[3];
    int k;

    for (k = 0; k < 3; k++)
        scanf("%d", &values[k]);

    int best = values[0];
    for (k = 1; k < 3; k++)
        if (values[k] > best)
            best = values[k];

    printf("%d\n", best);
    return 0;
}
