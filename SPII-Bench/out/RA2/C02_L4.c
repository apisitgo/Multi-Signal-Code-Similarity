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

// read a line, drop the line ending, return its length
static int read_clean(char *line, int cap)
{
	int n;
	if (fgets(line, cap, stdin) == NULL)
		line[0] = '\0';
	n = (int)strlen(line);
	while (n > 0 && (line[n-1] == '\n' || line[n-1] == '\r'))
		line[--n] = '\0';
	return n;
}

static void lower_all(char *line, int n)
{
	int k;
	for (k = 0; k < n; k++)
		line[k] = (char)tolower((unsigned char)line[k]);
}

static int check_pal(const char *line, int n)
{
	int k, half = n / 2;
	int isPal = 1;
	for (k = 0; k < half; k++)
		if (line[k] != line[n-1-k]) {
			isPal = 0;
			break;
		}
	return isPal;
}

int main(void)
{
	char line[MAXLINE];
	int n;

	n = read_clean(line, MAXLINE);
	lower_all(line, n);
	printf("%s\n", check_pal(line, n) ? "Palindrome" : "Not palindrome");
	return 0;
}
