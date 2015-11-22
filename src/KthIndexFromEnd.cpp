/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

int strLen(char *str) {
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

char KthIndexFromEnd(char *str, int K) {
	if (str == "" || str == nullptr)
		return '\0';
	return str[strLen(str) - K - 1];
}