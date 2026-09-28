#include <stdio.h>
#include <stdlib.h>

static int add_two(int first_operand, int second_operand)
{
    return first_operand + second_operand;
}

int main(void)
{
    int operand_a;
    int operand_b;

    scanf("%d", &operand_a);
    scanf("%d", &operand_b);

    int sum_result = add_two(operand_a, operand_b);
    printf("%d\n", sum_result);

    return 0;
}
