#include "..\projects.h"
#include <stdio.h>
#include <stdlib.h>
/*
	������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������
ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
*/
/*
	0.���������ַ�������n
	1.�����ַ������飬����n���ַ���
	2.�ֱ��жϸ��ַ����Ƿ���ϡ�����ȷ������
		a.�������YES
		b.���������NO
		(�ж�����: i. PAT��������Ϊ0
				   ii. PǰA����A1��PT��A����A2��T��A����A3���� A1*A2==A3)
*/
int judgeStr(char *str) {
	int ret = 1;
	int PCnt = 0;
	int TCnt = 0;
	int A1 = 0;
	int A2 = 0;
	int A3 = 0;
	int i = 0; 
	//�ֱ����A�ڸ��εĸ�����PT�Ƿ���Ϲ淶
	while (str[i] != '\0'){
		switch (str[i]) {
			case 'P': {
				PCnt++;
				if (PCnt > 1)ret = 0;
				break;
			}
			case 'T': {
				TCnt++;
				if (TCnt > 1)ret = 0;
				break;
			}
			case 'A': {
				if (TCnt > 0) {
					A3++;
				}
				else if (PCnt > 0) {
					A2++;
				}
				else {
					A1++;
				}
				break;
			}
			default:ret = 0;
		}
		i++;
		if (ret == 0)break;
	}
	if (PCnt*TCnt*A2 == 0 || A1*A2 != A3)ret = 0;
	return ret;
}

void iWantToPass() {
	//��ʼ��
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	char **samples = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++) {
		samples[i] = (char*)malloc(sizeof(char) * 100);
	}
	//�����ַ���
	for (i = 0; i < n; i++) {
		scanf("%s", samples[i]);
	}
	/*for (i = 0; i < n; i++) {
		printf("%s\n", samples[i]);
	}*/
	//�ж��ַ����Ƿ�������󣬲������Ӧ���
	for (i = 0; i < n; i++) {
		if (judgeStr(samples[i])) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	for (i = 0; i < n; i++) {
		free(samples[i]);
	}
	free(samples);
	
}