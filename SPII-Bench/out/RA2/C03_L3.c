// Programming Fundamentals - Lab exercise
// Task    : Basic Calculator #1 - Add Two Numbers
// Student : <student id> <full name>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    long first = 0, second = 0;
    long total;

    // get the two numbers
    scanf("%ld", &first);
    scanf("%ld", &second);

    // print the sum
    total = first + second;
    printf("%ld\n", total);
    return 0;
}
