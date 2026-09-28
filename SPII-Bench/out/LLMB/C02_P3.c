// palindrome checker (ignores upper/lower case)
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[4096];
    char rev[4096];
    int i, n;

    fgets(str, 4096, stdin);
    // remove the newline at the end
    n = strlen(str);
    while (n > 0 && (str[n-1] == '\n' || str[n-1] == '\r')) {
        str[n-1] = '\0';
        n--;
    }

    // make everything lowercase
    for (i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }

    // build the reversed string
    for (i = 0; i < n; i++) {
        rev[i] = str[n - 1 - i];
    }
    rev[n] = '\0';

    if (strcmp(str, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}
