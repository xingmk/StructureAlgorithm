#include <bits/stdc++.h>

using namespace std;
const int MAXSIZE = 100;  // 串的最大长度

class FixedLengthString {
public:
	FixedLengthString() {
		length_ = 0;
		memset(data_, '\0', sizeof(data_));
	}
	
	FixedLengthString(const char* str) {
		length_ = strlen(str);
		memset(data_, '\0', sizeof(data_));
		strncpy(data_, str, length_);
	}
	
	int length() const {
		return length_;
	}
	
	char operator[](int i) const {
		return data_[i];
	}
	
	char& operator[](int i) {
		return data_[i];
	}
	
private:
	char data_[MAXSIZE];
	int length_;
};

