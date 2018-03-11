#include "../projects.h"
/*
1.Input an integer(x<1000)
2.transform it into "BSn" form (For example: 234 to BBSSS1234)
3.output the answer
*/
void transform() {
	//initialize
	int x = 0;
	int B = 0;
	int S = 0;
	int n = 0;
	int i = 0;
	//input a positive integer x
	scanf("%d", &x);
	//get B, S, n
	B = x / 100;
	S = x % 100 / 10;
	n = x % 10;
	//output the answer
	for (i = 0; i < B; i++) {
		printf("B");
	}
	for (i = 0; i < S; i++) {
		printf("S");
	}
	for (i = 1; i <= n; i++) {
		printf("%d", i);
	}
}