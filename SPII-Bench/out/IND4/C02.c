/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #11 — Palindrome Check
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[1000];
    int i, j, ok = 1;
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    i = 0;
    j = strlen(s) - 1;
    while (j >= 0 && (s[j] == '\n' || s[j] == '\r')) j--;
    while (i < j) {
        if (tolower(s[i]) != tolower(s[j])) {
            ok = 0;
            break;
        }
        i++;
        j--;
    }
    if (ok) printf("Palindrome\n");
    else printf("Not palindrome\n");

    return 0;
}
