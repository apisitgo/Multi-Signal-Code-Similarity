// Programming Fundamentals - Lab exercise
// Task    : Basic Calculator #1 - Add Two Numbers
// Student : <student id> <full name>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long read_num(void) {
    char tok[64];
    if (scanf("%63s", tok) != 1)
        return 0;
    return strtol(tok, NULL, 10);
}

int main(void) {
    long first = 0, second = 0, total = 0;
    int count;

    // get the two numbers and accumulate them in a loop
    for (count = 0; count < 2; count++) {
        long v = read_num();
        if (count == 0) first = v;
        else second = v;
    }
    total = first;
    total += second;

    // print the sum
    printf("%ld\n", total);
    return 0;
}
