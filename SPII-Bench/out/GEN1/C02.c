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
    char s[256];
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        if (s[len-1] == '\n') len--;
    
        int is_palindrome = 1;
        for (int i = 0; i < len / 2; i++) {
            char c1 = tolower(s[i]);
            char c2 = tolower(s[len-1-i]);
            if (c1 != c2) {
                is_palindrome = 0;
                break;
            }
        }
        printf("%s\n", is_palindrome ? "Palindrome" : "Not palindrome");


    return 0;
}
