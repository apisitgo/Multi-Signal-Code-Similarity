/*
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #2 -- Shape Menu
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double MY_PI = 3.14159265358979323846;
const double HALF = 0.5;

int main(void) {
  int choice;
  double d1, d2;
  double area;

  scanf("%d", &choice);

  if (choice == 1) {             /* circle */
    scanf("%lf", &d1);
    area = MY_PI*d1*d1;
    printf("Area = %.2f\n", area);
  }
  else if (choice == 2) {        /* rectangle */
    scanf("%lf %lf", &d1, &d2);
    area = d1*d2;
    printf("Area = %.2f\n", area);
  }
  else if (choice == 3) {        /* triangle */
    scanf("%lf %lf", &d1, &d2);
    area = HALF*d1*d2;
    printf("Area = %.2f\n", area);
  }
  else {
    printf("Invalid choice\n");
  }
  return 0;
}
