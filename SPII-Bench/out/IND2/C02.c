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
    char text[1000];
    printf("Enter a line of text: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 0;
    }

    /* remove trailing newline */
    int len = strlen(text);
    while (len > 0 && (text[len - 1] == '\n' || text[len - 1] == '\r')) {
        text[len - 1] = '\0';
        len = len - 1;
    }

    int left = 0;
    int right = len - 1;
    int is_palindrome = 1;
    while (left < right) {
        char c1 = tolower(text[left]);
        char c2 = tolower(text[right]);
        if (c1 != c2) {
            is_palindrome = 0;
            break;
        }
        left = left + 1;
        right = right - 1;
    }

    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }

    return 0;
}
