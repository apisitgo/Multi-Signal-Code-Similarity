#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 4096

static size_t strip_line_ending(char *text)
{
    size_t length = strlen(text);
    while (length > 0 && (text[length - 1] == '\n' || text[length - 1] == '\r')) {
        text[length - 1] = '\0';
        length--;
    }
    return length;
}

static void to_lowercase_inplace(char *text, size_t length)
{
    for (size_t index = 0; index < length; index++) {
        text[index] = (char) tolower((unsigned char) text[index]);
    }
}

static int check_is_palindrome(const char *text, size_t length)
{
    for (size_t index = 0; index < length / 2; index++) {
        if (text[index] != text[length - 1 - index]) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    char input_line[MAX_LINE_LENGTH];

    if (fgets(input_line, sizeof(input_line), stdin) == NULL) {
        input_line[0] = '\0';
    }

    size_t line_length = strip_line_ending(input_line);
    to_lowercase_inplace(input_line, line_length);

    int result = check_is_palindrome(input_line, line_length);

    if (result) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }

    return 0;
}
