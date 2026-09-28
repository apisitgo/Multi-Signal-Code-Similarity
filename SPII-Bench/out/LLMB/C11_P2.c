/* Sorts integers ascending with an exchange sort that stops early when no swap occurs. */
#include <stdio.h>
#include <stdlib.h>

static void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

static void sort_ascending(int *v, int len)
{
    int swapped = 1, limit = len - 1;
    while (swapped && limit > 0) {
        swapped = 0;
        for (int i = 0; i < limit; i++)
            if (v[i] > v[i + 1]) {
                swap(&v[i], &v[i + 1]);
                swapped = 1;
            }
        limit--;
    }
}

int main(void)
{
    int len, i;
    scanf("%d", &len);
    int *v = malloc(sizeof(int) * (len > 0 ? len : 1));
    for (i = 0; i < len; i++)
        scanf("%d", &v[i]);

    sort_ascending(v, len);

    for (i = 0; i < len; i++)
        printf(i ? " %d" : "%d", v[i]);
    putchar('\n');
    free(v);
    return 0;
}
