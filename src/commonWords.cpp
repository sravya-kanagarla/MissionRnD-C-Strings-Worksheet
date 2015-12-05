/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int findHashIndex(char *str, int i) {
	int primeNUM[] = { 2, 3, 5, 7, 11 };
	int num = 0;
	while (i >= 0) {
		num += (str[i] * primeNUM[i]);
		i--;
	}
	return num;
}

void copy(char *res, char *str, int i) {
	res[i] = '\0';
	i -= 1;
	while (i >= 0) {
		res[i] = str[i];
		i--;
	}
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL || str1 == "" || str2 == "")
		return NULL;
	int i;
	int j = 0;
	int k = 0;
	int m = 0;
	int hash[10000] = { 0 };
	char ** result = (char **)malloc(sizeof(char *) * SIZE);
	for (i = 0; i < SIZE; i++)
		result[i] = (char *)malloc(sizeof(char) * SIZE);
	for (i = 0; str1[i] != '\0'; i++) {
		if (str1[i] == ' ') {
			if (str1[j] != ' ') {
				hash[findHashIndex(&str1[j], k - 1)]++;
				k = -1;
			}
			j = i + 1;
		}
		k++;
	}
	if (str1[j] != ' ' && str1[j] != '\0')
		hash[findHashIndex(&str1[j], k - 1)]++;
	k = 0;
	j = 0;
	for (i = 0; str2[i] != '\0'; i++) {
		if (str2[i] == ' ') {
			if (hash[findHashIndex(&str2[j], k - 1)] != 0) {
				copy(result[m], &str2[j], k);
				m++;
			}
			j = i + 1;
			k = -1;
		}
		k++;
	}
	if (hash[findHashIndex(&str2[j], k - 1)] != 0) {
		copy(result[m], &str2[j], k);
		m++;
	}
	result[m] = '\0';
	if (m == 0)
		return NULL;
	return result;
}