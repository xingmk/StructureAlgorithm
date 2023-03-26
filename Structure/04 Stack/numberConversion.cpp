#include<bits/stdc++.h>

using namespace std;

class Solution {
	public: 
		vector<int> conversion(int n, int d) {
			stack<int> st;
			vector<int> res;
			while (n) {
				st.push(n%d);
				n = n / d;
			}
			while (!st.empty()) {
				res.push_back(st.top());
				st.pop();
			}
			return res;
		}
};

int main(){
	return 0;
}
