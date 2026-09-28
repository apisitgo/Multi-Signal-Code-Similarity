#include <stdio.h>
#include <stdlib.h>

static void print_fibonacci_series(int term_count)
{
    long long previous = 0;
    long long current = 1;

    for (int position = 0; position < term_count; position++) {
        printf("%lld", previous);
        if (position < term_count - 1) {
            printf(" ");
        }
        long long next_value = previous + current;
        previous = current;
        current = next_value;
    }
    printf("\n");
}

int main(void)
{
    int term_count;
    scanf("%d", &term_count);

    print_fibonacci_series(term_count);

    return 0;
}
