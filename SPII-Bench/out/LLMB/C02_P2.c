/* Case-insensitive palindrome test on one line of input. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINE_MAX_LEN 4096

static int mirrors(const char *text, size_t left, size_t right)
{
    while (left < right) {
        int lc = tolower((unsigned char) text[left]);
        int rc = tolower((unsigned char) text[right]);
        if (lc != rc)
            return 0;
        left++;
        right--;
    }
    return 1;
}

int main(void)
{
    char line[LINE_MAX_LEN];
    size_t n;

    if (!fgets(line, sizeof line, stdin))
        line[0] = '\0';
    n = strcspn(line, "\r\n");
    line[n] = '\0';

    if (n == 0 || mirrors(line, 0, n - 1))
        puts("Palindrome");
    else
        puts("Not palindrome");
    return 0;
}
