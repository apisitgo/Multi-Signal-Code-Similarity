/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #11 — Palindrome Check
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char line[1024];
    if (fgets(line, sizeof line, stdin) == NULL) return 1;
    line[strcspn(line, "\r\n")] = '\0';

    int i = 0, j = (int)strlen(line) - 1;
    int is_pal = 1;
    while (i < j) {
        char x = line[i], y = line[j];
        if (x >= 'A' && x <= 'Z') x = (char)(x - 'A' + 'a');
        if (y >= 'A' && y <= 'Z') y = (char)(y - 'A' + 'a');
        if (x != y) { is_pal = 0; break; }
        i++; j--;
    }
    printf(is_pal ? "Palindrome\n" : "Not palindrome\n");

    return 0;
}
