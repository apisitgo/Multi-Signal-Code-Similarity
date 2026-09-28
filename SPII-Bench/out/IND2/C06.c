/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #14 — Sum and Average of Array
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int numbers[1000];
    int i = 0;
    while (i < n) {
        scanf("%d", &numbers[i]);
        i = i + 1;
    }

    int sum = 0;
    i = 0;
    while (i < n) {
        sum = sum + numbers[i];
        i = i + 1;
    }

    double average = (double) sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
