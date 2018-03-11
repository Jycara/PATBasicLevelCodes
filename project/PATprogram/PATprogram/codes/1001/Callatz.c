#include "..\projects.h"
/*
	callatz猜想，任意一个自然数n，为偶数时砍去一半；为奇数时把（3n+1）砍去一半。如此反复进行，最终得到n=1。
现在求一不超过1000的正整数n，需要多少次得到n=1。
	1.若n！=1，进行循环：
		a. 若n%2==0为偶数，n=n/2;步数cnt++;
		b. 若n%2!=0为奇数，n=(3*n+1)/2;步数cnt++;
	2.当n=1时，输出步数cnt。
*/
void callatz() {
	//初始化
	int n = 1;
	int cnt = 0;
	//输入n值
	scanf("%d", &n);
	//判断n是否为1，进入循环
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			cnt++;
		}
		else {
			n = (3 * n + 1) / 2;
			cnt++;
		}
	}
	printf("%d\n", cnt);
}