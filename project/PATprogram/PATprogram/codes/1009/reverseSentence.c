#include "../projects.h"
#include <stdlib.h>
#include <string.h>
/*
1009. Reverse the sentence.
1. Receive sentence by char;
2. Restore the sentence word by word into str[][81];
3. Output the sentence word by word reversely;
*/
void reverseSentence() {
	//initialize
	int i = -1;
	int cnt = 0;
	int endInput = 0;
	char *str1, *str2, *str3;
	str1 = (char*)malloc(sizeof(char) * 81);
	str2 = (char*)malloc(sizeof(char) * 81);
	str3 = (char*)malloc(sizeof(char) * 81);
	str2[0] = '\0';
	str3[0] = '\0';
	//input the sentence
	do {
		i++;
		scanf("%c", &str1[i]);
		if (str1[i] == ' ' || str1[i] == '\n') {
			if (str1[i] == '\n') {
				endInput = 1;
			}
			str1[i] = '\0';
			strcpy(str3, str1);
			if (str2[0] != '\0') {
				strcat(str3, " ");
			}
			strcat(str3, str2);
			strcpy(str2, str3);
			i = -1;
		}

	} while (!endInput);
	printf("%s\n", str2);
	free(str1);
	free(str2);
	free(str3);
}