#include "../projects.h"
/*
	����ѧ��������ѧ�š��ɼ���������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100�������
*/

typedef struct student {
	char name[20];
	char ID[20];
	int score;
} Stu;

void ranking() {
	//��ʼ��
	int max = 0;
	int maxNum = 0;
	int min = 100;
	int minNum = 0;
	int n = 0;
	int i = 0;
	//����ѧ����������ʼ��ѧ����Ϣ��
	scanf("%d", &n);
	if (n == 0) {
		exit(0);
	}
	Stu **students = (Stu **)malloc(sizeof(Stu*)*n);
	for (i = 0; i < n; i++) {
		students[i] = (Stu *)malloc(sizeof(Stu));
	}
	//�����ѧ����Ϣ
	for (i = 0; i < n; i++) {
		scanf("%s %s %d", students[i]->name, students[i]->ID, &students[i]->score);
		//printf("%s %s %d\n", students[i]->name, students[i]->ID, students[i]->score);
		if (students[i]->score <= min) {
			min = students[i]->score;
			minNum = i;
		}
		if (students[i]->score >= max) {
			max = students[i]->score;
			maxNum = i;
		}
	}
	//�ҳ���߷�ѧ������ͷ�ѧ��
	//�����߷�ѧ����Ϣ����ͷ�ѧ����Ϣ
	printf("%s %s\n", students[maxNum]->name, students[maxNum]->ID);
	printf("%s %s\n", students[minNum]->name, students[minNum]->ID);
	//printf("%s\n", students[minNum]->ID);
	for (i = 0; i < n; i++) {
		free(students[i]);
	}
	free(students);

}