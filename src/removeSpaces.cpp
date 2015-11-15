/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	if (!str || !(*str))
		return '\0';
	int i = -1;
	while (str[++i] && str[i] != ' ');
	int j = i;
	while (str[i++])
		if (str[i] != ' ')
			str[j++] = str[i];
}