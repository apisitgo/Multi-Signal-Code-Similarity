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
  scanf("%lf", &w);
  scanf("%lf", &h);
  return h*w;
}

static double tri_area(void) {
  double b, h;
  scanf("%lf", &b);
  scanf("%lf", &h);
  return HALF*b*h;
}

static void show_area(double area) {
  fputs("Area = ", stdout);
  printf("%.2f\n", area);
}

int main(void) {
  int choice;
  /* lookup table instead of an if/else chain */
  double (*shapes[])(void) = { NULL, circle_area, rect_area, tri_area };

  scanf("%d", &choice);

  if (choice < 1 || choice > 3) {
    puts("Invalid choice");
    return 0;
  }
  show_area(shapes[choice]());
  return 0;
}
