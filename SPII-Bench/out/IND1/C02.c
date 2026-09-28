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
    char str[100];
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }

    // Convert to lowercase and check palindrome
    int is_palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        char left = tolower(str[i]);
        char right = tolower(str[len - 1 - i]);
        if (left != right) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }

    return 0;
}
