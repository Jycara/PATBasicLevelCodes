#include "../projects.h"
/*
	读入学生姓名、学号、成绩，姓名、学号均为不超过10个字符的字符串，成绩为0到100间的整数
*/

typedef struct student {
	char name[20];
	char ID[20];
	int score;
} Stu;

void ranking() {
	//初始化
	int max = 0;
	int maxNum = 0;
	int min = 100;
	int minNum = 0;
	int n = 0;
	int i = 0;
	//输入学生个数，初始化学生信息表
	scanf("%d", &n);
	if (n == 0) {
		exit(0);
	}
	Stu **students = (Stu **)malloc(sizeof(Stu*)*n);
	for (i = 0; i < n; i++) {
		students[i] = (Stu *)malloc(sizeof(Stu));
	}
	//输入各学生信息
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
	//找出最高分学生与最低分学生
	//输出最高分学生信息与最低分学生信息
	printf("%s %s\n", students[maxNum]->name, students[maxNum]->ID);
	printf("%s %s\n", students[minNum]->name, students[minNum]->ID);
	//printf("%s\n", students[minNum]->ID);
	for (i = 0; i < n; i++) {
		free(students[i]);
	}
	free(students);

}