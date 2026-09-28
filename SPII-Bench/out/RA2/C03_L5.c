// Programming Fundamentals - Lab exercise
// Task    : Basic Calculator #1 - Add Two Numbers
// Student : <student id> <full name>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long read_num(void) {
    char tok[64] = "0";
    scanf("%63s", tok);
    return strtol(tok, NULL, 10);
}

static long add(long x, long y) {
    long s = x;
    s += y;
    return s;
}

int main(void) {
    long first = 0, second = 0;

    // get the two numbers
    first = read_num();
    second = read_num();

    // print the sum
    printf("%ld\n", add(first, second));
    return 0;
}
