#include <bits/stdc++.h> 
#define MaxStrlen 255

using namespace std;

typedef int status;
typedef unsigned char SString[MaxStrlen + 1];

//（1）串的定长顺序存储表示；
status StrAssign (SString& T, char *chars) {
	if (strlen(chars) > MaxStrlen) return -1;
	T[0] = strlen(chars);
	for (int i = 1; i <= T[0]; i++) {
		T[i] = *(chars + i - 1);
		return 1;
	}
}

//（2）串的联结操作；
status Concat(SString& T, SString s1, SString s2) {
	if (s1[0] + s2[0] <= MaxStrlen) {
		for (int i = 1; i <= s1[0]; i++) T[i] = s[i];
		for (int i = 1; i <= s2[0]; i++) T[s1[0] + i] = s2[i];
		T[0] = s1[0] + s2[0];
		return 1;
	}else if (s1[0] < MaxStrlen) {
		for (int i = 1; i <= s1[0]; i++) T[i] = s1[i];
		for (int i = 1; i < MaxStrlen - s1[0]; i++) T[s1[0] + i] = s2[i];
		T[0] = MaxStrlen;
		return -1;
	}else {
		for (int i = 1; i <= MaxStrlen; i++) T[i] = s1[i];
		T[0] = MaxStrlen;
		return -1;
	}
}

//（3）求子串操作；
status Index(SString T, SString s, int index) {
	if (index < 0 || index > s[0]) return -1;
	else {
		int i = 1;
		while (index < s[0] && i <= T[0]) {
			if (s[index] == T[i]) {
				index++;
				i++;
			} else {
				index = index - i + 2;
				i = 1;
			}
		}
		if (i > T[0]) {
			return index-T[0];
		}else return 0;
	}
}
