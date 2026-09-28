#include <stdio.h>
#include <stdlib.h>

static long long compute_gcd(long long value_one, long long value_two)
{
    long long remainder;
    while (value_two != 0) {
        remainder = value_one % value_two;
        value_one = value_two;
        value_two = remainder;
    }
    return value_one;
}

static long long compute_lcm(long long value_one, long long value_two)
{
    long long divisor = compute_gcd(value_one, value_two);
    return (value_one / divisor) * value_two;
}

int main(void)
{
    long long first_number;
    long long second_number;

    scanf("%lld %lld", &first_number, &second_number);

    printf("%lld\n", compute_lcm(first_number, second_number));

    return 0;
}
