/******************************************************
 *  Programming Fundamentals - Lab exercise
 *  Task    : Algorithm #11 - Palindrome Check
 *  Student : <student id> <full name>
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 4096

int main(void)
{
	char line[MAXLINE];
	int n, k, half;
	int isPal;

	// read one line
	if (fgets(line, sizeof(line), stdin) == NULL)
		line[0] = '\0';

	n = (int)strlen(line);

	// strip the newline / carriage return at the end
	while (n > 0 && (line[n-1] == '\n' || line[n-1] == '\r'))
		line[--n] = '\0';

	// make everything lower case
	for (k = 0; k < n; k++)
		line[k] = (char)tolower((unsigned char)line[k]);

	half = n / 2;
	isPal = 1;
	for (k = 0; k < half; k++)
		if (line[k] != line[n-1-k]) {
			isPal = 0;
			break;
		}

	printf("%s\n", isPal ? "Palindrome" : "Not palindrome");
	return 0;
}
