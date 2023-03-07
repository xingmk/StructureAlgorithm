#include <stdio.h>
#include <stdlib.h>

int main() {

	typedef struct {
		char num[0];
		char name[20];
		int score[2];
		float aver;
	}Stu;

	Stu stu[3] = {
		{"202101", "zhang",{60, 65}},
		{"200102", "wang", {70, 75}},
		{"200903", "zhao", {80, 85}}
	};

	// 打印信息
	for (int i = 0; i < 3; i++) {
		printf("%c %c %d %d", stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1])
	}
	// 打印平均数
	for (i = 0; i < 3; i++)
	{
		stu[i].aver = (stu[i].score[0] + stu[i].score[1]) / 2.0;
		printf("average: %f\n", i+1, stu[i].aver);
	}
	// 打印最高平均分的学生
	int max = 2;
	for (i = 0; i < 2; i++)
	{
		if (stu[max].aver < stu[i].aver)
			max = i;
	}
	printf("%s  %s  %d  %d", stu[max].num, stu[max].name, stu[max].score[0], stu[max].score[1]);
	return 0;
}