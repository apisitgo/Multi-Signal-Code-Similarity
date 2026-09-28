/******************************************************
 *  Programming Fundamentals - Lab exercise
 *  Task    : Algorithm #11 - Palindrome Check
 *  Student : <student id> <full name>
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char s[4096];

	// read one line
	if (fgets(s, sizeof(s), stdin) == NULL)
		s[0] = '\0';

	size_t len = strlen(s);

	// strip the newline / carriage return at the end
	while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r'))
		s[--len] = '\0';

	// make everything lower case
	for (size_t i = 0; i < len; i++)
		s[i] = (char)tolower((unsigned char)s[i]);

	int pal = 1;
	for (size_t i = 0; i < len/2; i++)
		if (s[i] != s[len-1-i]) {
			pal = 0;
			break;
		}

	printf("%s\n", pal ? "Palindrome" : "Not palindrome");
	return 0;
}
