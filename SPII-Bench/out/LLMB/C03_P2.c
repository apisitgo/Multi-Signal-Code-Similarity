/* Adds two integers read from standard input. */
#include <stdio.h>

static int read_int(void)
{
    int v = 0;
    scanf("%d", &v);
    return v;
}

int main(void)
{
    int total = read_int();
    total += read_int();
    printf("%d\n", total);
    return 0;
}
