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

static double circle_area(void) {
  double r;
  scanf("%lf", &r);
  return MY_PI*r*r;
}

static double rect_area(void) {
  double w, h;
  scanf("%lf %lf", &w, &h);
  return w*h;
}

static double tri_area(void) {
  double b, h;
  scanf("%lf %lf", &b, &h);
  return HALF*b*h;
}

static void show_area(double area) {
  printf("Area = %.2f\n", area);
}

int main(void) {
  int choice;

  scanf("%d", &choice);

  if (choice == 1)
    show_area(circle_area());
  else if (choice == 2)
    show_area(rect_area());
  else if (choice == 3)
    show_area(tri_area());
  else
    printf("Invalid choice\n");
  return 0;
}
