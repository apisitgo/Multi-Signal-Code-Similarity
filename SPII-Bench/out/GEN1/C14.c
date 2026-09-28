/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #2 — Simple Calculator
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int a, b;
        char op;
        scanf("%d %c %d", &a, &op, &b);

        if (op == '+') {
            printf("%d\n", a + b);
        } else if (op == '-') {
            printf("%d\n", a - b);
        } else if (op == '*') {
            printf("%d\n", a * b);
        } else if (op == '/') {
            if (b == 0) {
                printf("Error: division by zero\n");
            } else {
                printf("%d\n", a / b);
            }
        } else {
            printf("Error: invalid operator\n");
        }


    return 0;
}
