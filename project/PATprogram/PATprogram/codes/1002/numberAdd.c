#include "../projects.h"
//读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
/*
	考虑到自然数n可能很大，采用一位一位接收，累加入和sum，再将sum值一位位转换成拼音输出。
		1.循环读取1位数据
			a. 将数据累加进和sum
		2.将sum值按位以拼音输出
			a. 循环计算sum/digit;digit=digit*10;直到sum/digit=0;（计算sum值最高位位数）
			b. 循环取出sum值最高位（sum/(digit/10))，输出对应拼音，将sum值最高位去除，直到所有位数被取出。

*/
void numberAdd() {
	//初始化
	int sum = 0;
	int digit = 1;
	char temp = '0';
	char *pinyin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu", };
	//读入数据，并计算各位之和
	do {
		sum = sum + (int)(temp-'0');
		scanf("%c", &temp);
	} while (temp != '\n');
	//求sum值最高位位数
	while (sum / digit != 0) {
		digit = digit * 10;
	}
	digit = digit / 10;
	//循环取出sum值最高位，输出相应拼音
	while (digit!=0) {
		printf("%s", pinyin[sum / digit]);
		sum = sum % digit;
		digit = digit / 10;
		if (digit != 0) {
			printf(" ");
		}
	}
}