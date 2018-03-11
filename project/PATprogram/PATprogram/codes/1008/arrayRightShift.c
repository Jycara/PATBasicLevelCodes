#include "../projects.h"
#include <stdio.h>
#include <stdlib.h>
/*
1008. Right shift of array. Shift the element in array a[n]
from {a0£¬a1, ... an-1} to {an-m, ... an-1, a0, a1, ... an-m-1}
1. m=m%n;
2. split a[n] as m group, shift every group respectively.
*/
void arrayRigthShift() {
	//initialize
	int n = 0;
	int m = 0;
	int temp = 0;
	int i = 0;
	int j = 0;
	int *a;
	scanf("%d %d", &n, &m);
	a = (int*)malloc(sizeof(int)*n);
	//input array
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//right shift the numbers
	m = m%n;
	for (i = 0; i < m; i++) {
		j = (i + m) % n;
		while (j > i) {
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			j = (j + m) % n;
		}
		if (j < i) {
			break;
		}
	}
	//output the shifted array;
	for (i = 0; i < n - 1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d", a[i]);
	free(a);
}