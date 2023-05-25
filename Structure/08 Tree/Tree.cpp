#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

public:
	// 前序
	void traversalBef(TreeNode* cur, vector<int> res) {
		if (!cur) return;
		
		res.push_back(cur->val);
		traversalBef(cur->left, res);
		traversalBef(cur->right, res);
	}
	
	// 中序
	void traversalMid(TreeNode* cur, vector<int> res) {
		if (!cur) return;
		
		traversalMid(cur->left, res);
		res.push_back(cur->val);
		traversalMid(cur->right, res);
	}
	
	// 后序
	void traversalAft(TreeNode* cur, vector<int> res) {
		if (!cur) return;
		
		traversalAft(cur->left, res);
		traversalAft(cur->right, res);
		res.push_back(cur->val);
	}

	// 前序
	vector<int> traversalsBef(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
	
		if (!root) return res;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top(); 
			st.pop();
			res.push_back(node->val);
			if (node->left) st.push(node->left);
			if (node->right) st.push(node->right);
		}	
	return res;
	}
	
	// 中序
	vector<int> traversalMid(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur || !st.empty()) {
			if (cur) {
				st.push(cur);
				cur = cur->left;
			} else {
				cur = st.top();
				st.pop();
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
	return res;
	}
	
	
	// 后序
	vector<int> traversalsAft(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		
		if (!root) return res;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top(); 
			st.pop();
			res.push_back(node->val);
			if (node->left) st.push(node->left);
			if (node->right) st.push(node->right);
		}
	reverse(res.begin(), res.end());
	return res;
	}
};
