#include <bits/stdc++.h>

using namespace std;

class Soultion {
public:
	bool isValid (string s) {
		if (s.size() % 2 != 0) return false;
		stack<char> st;
		for (int i : s) {
			if (i == '(') st.push(')');
			else if (i == '{') st.push('}'); 
			else if (i == '[') st.push(']');
			else if (st.empty() || st.top() != i) return false;
			else st.pop();
		}
		return st.empty();
	}	
};

int main(){
	return 0;
}
