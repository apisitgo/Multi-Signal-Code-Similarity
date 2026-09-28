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
        scanf("%d", &n);
        int arr[1000], sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        printf("Sum = %d\n", sum);
        printf("Average = %.2f\n", (double)sum / n);


    return 0;
}
