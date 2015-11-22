/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	if (str == nullptr || str == "")
		return '\0';
	int i;
	int j = 0;
	for (i = 0; str[i] != '\0' && str[i] != ' '; i++);
	while (str[i + j] != '\0') {
		if (str[i + j] == ' ')
			j++;
		else {
			str[i] = str[i + j];
			i++;
		}
	}
	str[i] = '\0';
}