/*
 * Programming Fundamentals - Lab exercise
 * Task    : Geometry Area #2 -- Shape Menu
 * Student : <student id> <full name>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MY_PI 3.14159265358979323846

int main(void) {
  int choice;
  scanf("%d", &choice);

  if (choice == 1) {             /* circle */
    double radius;
    scanf("%lf", &radius);
    printf("Area = %.2f\n", MY_PI*radius*radius);
  }
  else if (choice == 2) {        /* rectangle */
    double wid, hgt;
    scanf("%lf %lf", &wid, &hgt);
    printf("Area = %.2f\n", wid*hgt);
  }
  else if (choice == 3) {        /* triangle */
    double base, height;
    scanf("%lf %lf", &base, &height);
    printf("Area = %.2f\n", 0.5*base*height);
  }
  else {
    printf("Invalid choice\n");
  }
  return 0;
}
