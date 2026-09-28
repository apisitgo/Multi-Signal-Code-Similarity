#include <stdio.h>
#include <stdlib.h>

static int pick_greater(int first_value, int second_value)
{
    if (first_value > second_value) {
        return first_value;
    }
    return second_value;
}

int main(void)
{
    int value_one = 0;
    int value_two = 0;
    int value_three = 0;

    scanf("%d %d %d", &value_one, &value_two, &value_three);

    int partial_max = pick_greater(value_two, value_three);
    int overall_max = pick_greater(value_one, partial_max);

    printf("%d\n", overall_max);

    return 0;
}
