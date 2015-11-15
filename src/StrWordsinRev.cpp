/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char * str, int first, int last) {
	char temp;
	while (first < last) {
		temp = str[first];
		str[first ++] = str[last];
		str[last--] = temp;
	}
}

void str_words_in_rev(char *input, int len){
	// reversing entire string
	reverse(input, 0, len - 1);
	//reversing back each word
	int i = -1, wordBegin;
	// finding and reversing next words
	while (++i < len) {
		if (input[i] != ' ') {
			wordBegin = i;
			while (++i < len && input[i] != ' ');
			reverse(input, wordBegin, i - 1);
		}
	}
}
