// Programming Fundamentals - Lab exercise
// Task    : Basic Calculator #1 - Add Two Numbers
// Student : <student id> <full name>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int first;
    int second;

    // get the two numbers
    scanf("%d", &first);
    scanf("%d", &second);

    // print the sum
    printf("%d\n", first+second);
    return 0;
}
