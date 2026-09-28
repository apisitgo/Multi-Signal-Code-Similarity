/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #11 — Palindrome Check
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

void chomp(char *s)
{
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) s[--n] = '\0';
}

int is_pal(const char *s)
{
    int i = 0, j = (int)strlen(s) - 1;
    while (i < j) {
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return 0;
        i++;
        j--;
    }
    return 1;
}

int main(void)
{
    char buf[1024];
    if (!fgets(buf, sizeof buf, stdin)) buf[0] = '\0';
    chomp(buf);
    printf("%s\n", is_pal(buf) ? "Palindrome" : "Not palindrome");
    return 0;
}
