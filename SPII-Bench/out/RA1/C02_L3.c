/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task: Algorithm #11 - Palindrome Check
 * (redone in my own style)
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
        char line[4096];
        size_t n;
        int isPal;
        int unused_flag = 0;

        if (fgets(line, sizeof(line), stdin) == NULL)
                line[0] = '\0';

        n = strlen(line);
        while (n > 0 && (line[n - 1] == '\n' || line[n - 1] == '\r'))
                line[--n] = '\0';

        for (size_t k = 0; k < n; k++)
                line[k] = (char) tolower((unsigned char) line[k]);

        isPal = 1;
        for (size_t k = 0; k < n / 2; k++)
                if (line[k] != line[n - 1 - k]) { isPal = 0; break; }

        (void) unused_flag;
        printf("%s\n", isPal ? "Palindrome" : "Not palindrome");

        return 0;
}
