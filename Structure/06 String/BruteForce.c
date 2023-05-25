#include <stdio.h>
#include <string.h>

int bruteForce(char* s, char* p) {
	int i = 0, j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen) {
		if (s[i] == p[j]) { 
			i++;
			j++;
		} else { 
			i = i - j + 1;
			j = 0;
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

