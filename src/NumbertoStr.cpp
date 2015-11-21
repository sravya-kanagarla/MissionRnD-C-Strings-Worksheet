/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void reverse(char *str, int len) {
	int i;
	char t;
	for (i = 0; i < len; i++) {
		t = str[i];
		str[i] = str[len];
		str[len] = t;
		len--;
	}
}

int copyInt(int decimalPart, char *str) {
	int i;
	for (i = 0; decimalPart; decimalPart /= 10) {
		str[i++] = (decimalPart % 10) + '0';
	}
	str[i] = '\0';
	reverse(str, i - 1);
	return i;
}

void number_to_str(float number, char *str, int afterdecimal){
	int index = 0;
	int decimalPart;
	if (number < 0) {
		str[index++] = '-';
		number *= -1;
	}
	decimalPart = (int)number;
	index = copyInt(decimalPart, &str[index]);
	if (str[0] == '-')
		index++;
	number -= (float)decimalPart;
	decimalPart = 1;
	if (afterdecimal) {
		str[index++] = '.';
		while (afterdecimal) {
			decimalPart *= 10;
			afterdecimal--;
		}
		number *= decimalPart;
		copyInt((int)number, &str[index]);
	}
}
