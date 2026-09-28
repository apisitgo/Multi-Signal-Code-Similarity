#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char buf[4096];
    if (!fgets(buf, sizeof(buf), stdin)) buf[0] = '\0';

    size_t n = strlen(buf);
    while (n > 0 && (buf[n - 1] == '\n' || buf[n - 1] == '\r')) buf[--n] = '\0';
    for (size_t k = 0; k < n; k++) buf[k] = (char) tolower((unsigned char) buf[k]);

    int is_pal = 1;
    size_t lo = 0, hi = n > 0 ? n - 1 : 0;
    while (lo < hi) {
        if (buf[lo] != buf[hi]) { is_pal = 0; break; }
        lo++; hi--;
    }

    puts(is_pal ? "Palindrome" : "Not palindrome");
    return 0;
}
