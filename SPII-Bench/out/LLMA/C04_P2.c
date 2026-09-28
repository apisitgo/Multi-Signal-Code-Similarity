#include <stdio.h>
#include <stdlib.h>

static int is_divisor_of(int candidate, int target)
{
    return target % candidate == 0;
}

int main(void)
{
    int target_number;
    scanf("%d", &target_number);

    int emitted_count = 0;
    for (int candidate = 1; candidate <= target_number; candidate++) {
        if (is_divisor_of(candidate, target_number)) {
            if (emitted_count > 0) {
                printf(" ");
            }
            printf("%d", candidate);
            emitted_count++;
        }
    }
    printf("\n");

    return 0;
}
