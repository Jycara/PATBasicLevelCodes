#include "../projects.h"
//����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�
/*
	���ǵ���Ȼ��n���ܴܺ󣬲���һλһλ���գ��ۼ����sum���ٽ�sumֵһλλת����ƴ�������
		1.ѭ����ȡ1λ����
			a. �������ۼӽ���sum
		2.��sumֵ��λ��ƴ�����
			a. ѭ������sum/digit;digit=digit*10;ֱ��sum/digit=0;������sumֵ���λλ����
			b. ѭ��ȡ��sumֵ���λ��sum/(digit/10))�������Ӧƴ������sumֵ���λȥ����ֱ������λ����ȡ����

*/
void numberAdd() {
	//��ʼ��
	int sum = 0;
	int digit = 1;
	char temp = '0';
	char *pinyin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu", };
	//�������ݣ��������λ֮��
	do {
		sum = sum + (int)(temp-'0');
		scanf("%c", &temp);
	} while (temp != '\n');
	//��sumֵ���λλ��
	while (sum / digit != 0) {
		digit = digit * 10;
	}
	digit = digit / 10;
	//ѭ��ȡ��sumֵ���λ�������Ӧƴ��
	while (digit!=0) {
		printf("%s", pinyin[sum / digit]);
		sum = sum % digit;
		digit = digit / 10;
		if (digit != 0) {
			printf(" ");
		}
	}
}