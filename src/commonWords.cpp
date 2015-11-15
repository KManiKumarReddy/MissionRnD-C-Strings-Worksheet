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

char * wordExists(char * word, int begin, int end, char * text) {
	int i = 0, j;
	while (text[i] && text[i] == ' ') i++;
	while (text[i]) {
		for (j = begin; j <= end && word[j] == text[i] && text[i]; j++, i++);
		if (j == end + 1 && (text[i] == ' ' || !text[i])) {
			// copying word to a new string and returning it
			char *string = (char *)malloc(sizeof(char)* SIZE);
			string[end - begin + 1] = 0;
			while (begin <= end)
				string[(end--) - begin] = word[end];
			return string;
		}
		if (text[i] == ' ') {
			while (text[i] && text[i] == ' ') i++;
		}
		else {
			while (text[i] && text[i] != ' ') i++;
			while (text[i] && text[i] == ' ') i++;
		}
	}
	return NULL;
}


char ** commonWords(char *str1, char *str2) {
	if (!str1 || !str1 || !(*str1) || !(*str2))
		return NULL;
	int i = -1, wordBegin, count = 0;
	char **result = (char **)calloc(SIZE, sizeof(char*)), *temp;
	while (str1[++i]) {
		if (str1[i] != ' ') {
			wordBegin = i;
			while (str1[++i] && str1[i] != ' ');
			if (temp = wordExists(str1, wordBegin, i - 1, str2))
				*(result + count++) = temp;
		}
	}
	return count > 0 ? result : NULL;
}