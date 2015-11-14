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

int power10(int n) {
	int res = 1;
	while (n--) res *= 10;
	return res;
}

void rev(char * str, int first, int last) {
	char temp;
	while (first < last) {
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first ++;
		last--;
	}
}

void number_to_str(float number, char *str,int afterdecimal){
	int n = (int)number, f = (int)((number - n) * power10(afterdecimal)), i= 0;
	if (number < 0)
		str[i++] = '-';
	// changing -ves to +ves
	if (n < 0) n = -n;
	if (f < 0) f = -f;
	str[i++] = n % 10 + '0';
	while (n /= 10)
		str[i++] = n % 10 + '0';
	rev(str, number < 0 ? 1 : 0, i - 1);
	if (afterdecimal) {
		str[i++] = '.';
		str[i++] = f % 10 + '0';
		while (f /= 10)
			str[i++] = f % 10 + '0';
		rev(str, i - afterdecimal, i - 1);
	}
	str[i] = 0;
}
