#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* data;
	int length;
} String;

// 初始化字符串
void initString(String* str, const char* s) {
	str->length = strlen(s);
	str->data = (char*)malloc(str->length + 1);
	strcpy(str->data, s);
}

// 销毁字符串
void destroyString(String* str) {
	free(str->data);
	str->length = 0;
}

int main() {
	String s1, s2, s3;
	initString(&s1, "hello");
	initString(&s2, s1.data);
	initString(&s3, "");
	s3 = s2;
	printf("%s\n", s1.data);
	printf("%s\n", s2.data);
	printf("%s\n", s3.data);
	destroyString(&s1);
	destroyString(&s2);
	destroyString(&s3);
	return 0;
}

