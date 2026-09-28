#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    /* check if a word is a palindrome */
    char word[4096];
    fgets(word, 4096, stdin);

    int len = strlen(word);
    while (len > 0 && (word[len - 1] == '\n' || word[len - 1] == '\r')) {
        word[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }

    int ok = 1;
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) {
            ok = 0;
        }
    }

    if (ok == 1) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }

    return 0;
}
