/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void strip_newline(char *text)
{
    size_t n = strlen(text);
    while (n > 0 && (text[n - 1] == '\n' || text[n - 1] == '\r'))
        text[--n] = '\0';
}

static int is_palindrome(const char *text)
{
    size_t left = 0;
    size_t right = strlen(text);
    while (right > left + 1) {
        int a = tolower((unsigned char) text[left]);
        int b = tolower((unsigned char) text[right - 1]);
        if (a != b) return 0;
        left++;
        right--;
    }
    return 1;
}

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) line[0] = '\0';
    strip_newline(line);
    puts(is_palindrome(line) ? "Palindrome" : "Not palindrome");
    return 0;
}
