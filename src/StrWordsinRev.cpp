/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void strRev(char *str, int start, int end) {
	char t;
	while (start < end) {
		t = str[start];
		str[start] = str[end];
		str[end] = t;
		start++;
		end--;
	}
}

void str_words_in_rev(char *input, int len) {
	if (input == NULL || input == "")
		return;
	int startIndex = 0;
	int endIndex = 0;
	char *pointer;
	strrev(input);
	pointer = strchr(input, ' ');
	while (pointer != NULL) {
		endIndex = pointer - input;
		strRev(input, startIndex, endIndex - 1);
		startIndex = endIndex + 1;
		pointer = strchr(&input[startIndex], ' ');
	}
	strRev(input, startIndex, len - 1);
}
