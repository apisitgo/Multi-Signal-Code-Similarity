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
	char line[4096];

	// read one line
	if (fgets(line, sizeof(line), stdin) == NULL)
		line[0] = '\0';

	size_t n = strlen(line);

	// strip the newline / carriage return at the end
	while (n > 0 && (line[n-1] == '\n' || line[n-1] == '\r'))
		line[--n] = '\0';

	// make everything lower case
	for (size_t k = 0; k < n; k++)
		line[k] = (char)tolower((unsigned char)line[k]);

	int isPal = 1;
	for (size_t k = 0; k < n/2; k++)
		if (line[k] != line[n-1-k]) {
			isPal = 0;
			break;
		}

	printf("%s\n", isPal ? "Palindrome" : "Not palindrome");
	return 0;
}
