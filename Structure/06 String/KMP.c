#include <stdio.h>
#include <string.h>

// 计算next
void getNext(char* p, int* next) {
	int i = 0, j = -1;
	int pLen = strlen(p);
	next[0] = -1;
	while (i < pLen) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int kmp(char* s, char* p) {
	int i = 0, j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	int next[pLen];
	getNext(p, next);
	while (i < sLen && j < pLen) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else  
		return -1;
}

int main() {
	return 0;
}

