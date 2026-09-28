/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #11 - Palindrome Check
 * (redone in my own style)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static size_t readTrimmed(char *line, size_t cap)
{
        if (fgets(line, (int) cap, stdin) == NULL)
                line[0] = '\0';
        size_t n = strlen(line);
        while (n > 0 && (line[n - 1] == '\n' || line[n - 1] == '\r'))
                line[--n] = '\0';
        return n;
}

static void toLowerInPlace(char *line, size_t n)
{
        size_t k = 0;
        while (k < n) {
                line[k] = (char) tolower((unsigned char) line[k]);
                k += 1;
        }
}

static int checkPalindrome(const char *line, size_t n)
{
        int unused_flag = 0;
        (void) unused_flag;
        size_t k = 0;
        size_t half = n / 2;
        for (; k < half; k++)
                if (line[k] != line[n - 1 - k]) return 0;
        return 1;
}

int main(void)
{
        char line[4096];
        size_t n = readTrimmed(line, sizeof(line));
        toLowerInPlace(line, n);
        int isPal = checkPalindrome(line, n);

        printf("%s\n", isPal ? "Palindrome" : "Not palindrome");

        return 0;
}
