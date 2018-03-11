#include "..\projects.h"
#include <stdlib.h>
/*
构建1维数组a[100]，初始化均为0值，将数组对应接收到的数的位置处赋值1，
再按Callatz验证方法，将覆盖的数对应位置赋0
*/
void callatz2() {
	//初始化
	int a[101] = { 0, };
	int *numbers;
	int n = 0;
	int i = 0;
	int cnt = 0;

	//输入需验证个数及各数值，将各数值对应位置处数组值赋1
	scanf("%d", &n);
	numbers = (int*)malloc(sizeof(int)*n);
	cnt = n;
	for (i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
		a[numbers[i]] = 1;
	}
	/*for (i = 0; i < 101; i++) {
	printf("%d", a[i]);
	}
	printf("\n");*/
	//按Callatz验证方法对所输入数据逐一进行判定，将被覆盖处赋0
	for (i = 0; i < n; i++) {
		//printf("%d:", numbers[i]);
		while (numbers[i] != 1) {
			if (numbers[i] % 2 == 0) {
				numbers[i] = numbers[i] / 2;
			}
			else {
				numbers[i] = (3 * numbers[i] + 1) / 2;
			}
			if (numbers[i] <= 100) {
				if (a[numbers[i]]) {
					a[numbers[i]] = 0;
					cnt--;
				}
			}
			//printf("%d ", numbers[i]);
		}
		//printf("\n");
	}
	for (i = 100; i >= 0; i--) {
		if (a[i] == 1) {
			printf("%d", i);
			if (cnt > 1) {
				printf(" ");
				cnt--;
			}
		}
	}
}