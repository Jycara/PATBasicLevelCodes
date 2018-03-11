#include "..\projects.h"
#include <stdlib.h>
/*
����1ά����a[100]����ʼ����Ϊ0ֵ���������Ӧ���յ�������λ�ô���ֵ1��
�ٰ�Callatz��֤�����������ǵ�����Ӧλ�ø�0
*/
void callatz2() {
	//��ʼ��
	int a[101] = { 0, };
	int *numbers;
	int n = 0;
	int i = 0;
	int cnt = 0;

	//��������֤����������ֵ��������ֵ��Ӧλ�ô�����ֵ��1
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
	//��Callatz��֤������������������һ�����ж����������Ǵ���0
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