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
	while (n > 0 && strchr("\r\n", line[n-1]) != NULL) {
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

static int check_pal(const char *line, int n)
{
	int left = 0, right = n - 1;
	int isPal = 1;
	while (left < right) {
		if (line[left] != line[right]) {
			isPal = 0;
			break;
		}
		left++;
		right--;
	}
	return isPal;
}

int main(void)
{
	char line[MAXLINE];
	int n;

	n = read_clean(line, MAXLINE);
	lower_all(line, n);
	puts(check_pal(line, n) ? "Palindrome" : "Not palindrome");
	return 0;
}
