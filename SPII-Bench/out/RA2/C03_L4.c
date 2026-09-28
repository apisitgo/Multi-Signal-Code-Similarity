// Programming Fundamentals - Lab exercise
// Task    : Basic Calculator #1 - Add Two Numbers
// Student : <student id> <full name>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long read_num(void) {
    long v = 0;
    scanf("%ld", &v);
    return v;
}

static long add(long x, long y) {
    return x + y;
}

int main(void) {
    long first = 0, second = 0;
    long total;

    // get the two numbers
    first = read_num();
    second = read_num();

    // print the sum
    total = add(first, second);
    printf("%ld\n", total);
    return 0;
}
