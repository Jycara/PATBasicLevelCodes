#include "../projects.h"
#include <stdint.h>
#include <math.h>
//#include "codes\projects.h"
/*
1007. Count the number of pairs of prime numbers between which the difference is 2;
1. Input the scale n;
2. Calculate prime numbers from 2 to n:
a. Save the latest 2 adjacent prime number in x1 and x2 (x2>x1)
b. Judge if dn=x2-x1 equals 2 or not:
yes: counter++;
no : continue to calculate the next pair of numbers;
3. Output the value of counter;
*/
int isPrime(int n) {
	/* Judge whether number n is prime or not.*/
	int i = 0;
	int ret = 1;
	for (i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			ret = 0;
		}
	}
	return ret;
}
void primePairCounter() {
	//initialize
	int n = 0;
	int counter = 0;
	int i = 0;
	int x1 = 2, x2 = 2;
	int dn = 0;

	//input n
	scanf("%d", &n);

	//calculate prime numbers
	for (i = 2; i <= n; i++) {
		if (isPrime(i)) {
			x1 = x2;
			x2 = i;
			dn = x2 - x1;
			if (dn == 2) {
				counter++;
			}
		}
	}
	printf("%d", counter);
}