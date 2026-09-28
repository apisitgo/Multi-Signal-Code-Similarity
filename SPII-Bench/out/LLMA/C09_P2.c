#include <stdio.h>
#include <stdlib.h>

static void print_row(int leading_spaces, int star_count)
{
    for (int s = 0; s < leading_spaces; s++) {
        printf(" ");
    }
    for (int s = 0; s < star_count; s++) {
        printf("*");
    }
    printf("\n");
}

int main(void)
{
    int height;
    scanf("%d", &height);

    for (int row_number = 1; row_number <= height; row_number++) {
        int spaces_needed = height - row_number;
        int stars_needed = 2 * row_number - 1;
        print_row(spaces_needed, stars_needed);
    }

    return 0;
}
