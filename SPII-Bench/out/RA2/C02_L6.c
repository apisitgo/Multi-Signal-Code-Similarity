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
	if (!fgets(line, cap, stdin))
		*line = 0;
	n = (int)strlen(line);
	for (;;) {
		if (n == 0) break;
		if (strchr("\r\n", line[n-1]) == NULL) break;
		n = n - 1;
		line[n] = 0;
	}
	return n;
}

static void lower_all(char *line, int n)
{
	int k = 0;
	while (k < n) {
		line[k] = (char)tolower((unsigned char)line[k]);
		k += 1;
	}
}

// recursive check from both ends towards the middle
static int check_pal(const char *line, int left, int right)
{
	if (left >= right)
		return 1;
	if (line[left] != line[right])
		return 0;
	return check_pal(line, left + 1, right - 1);
}

int main(void)
{
	char line[MAXLINE];
	int n;

	n = read_clean(line, MAXLINE);
	lower_all(line, n);
	if (!check_pal(line, 0, n - 1))
		puts("Not palindrome");
	else
		puts("Palindrome");
	return 0;
}
