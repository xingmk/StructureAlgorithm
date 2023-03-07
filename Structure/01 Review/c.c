#include <stdio.h>
#include <stdlib.h>

int main() {
	typedef struct
	{
		char num[10]; 
		char name[20];
		int score;
	}Stu; 
	
	Stu stu[4] = {{"200901", "Zhang", 70},
				  {"200902", "Wang", 80}, 
				  {"200903", "Zhao", 65}, 
				  {"200904", "Zhou", 95} 
				 };
	// 打印信息
	for (int i = 0; i < 4; i++) {
		printf("%c %c %d ", stu[i].num, stu[i].name, stu[i].score);
	}
	// 冒泡排序
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (stu[j].score < stu[j + 1].score) {
				Stu temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	// 打印信息
	for (int i = 0; i < 4; i++) {
		printf("%c %c %d ", stu[i].num, stu[i].name, stu[i].score);
	}
	return 0;
}