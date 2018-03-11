#include "..\projects.h"
#include <stdio.h>
#include <stdlib.h>
/*
	“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，
系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
*/
/*
	0.读入需检测字符串个数n
	1.创建字符串数组，读入n个字符串
	2.分别判断各字符串是否符合“答案正确”需求
		a.符合输出YES
		b.不符合输出NO
		(判断条件: i. PAT个数均不为0
				   ii. P前A个数A1，PT间A个数A2，T后A个数A3满足 A1*A2==A3)
*/
int judgeStr(char *str) {
	int ret = 1;
	int PCnt = 0;
	int TCnt = 0;
	int A1 = 0;
	int A2 = 0;
	int A3 = 0;
	int i = 0; 
	//分别计数A在各段的个数及PT是否符合规范
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
	//初始化
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	char **samples = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++) {
		samples[i] = (char*)malloc(sizeof(char) * 100);
	}
	//读入字符串
	for (i = 0; i < n; i++) {
		scanf("%s", samples[i]);
	}
	/*for (i = 0; i < n; i++) {
		printf("%s\n", samples[i]);
	}*/
	//判断字符串是否符合需求，并输出相应结果
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