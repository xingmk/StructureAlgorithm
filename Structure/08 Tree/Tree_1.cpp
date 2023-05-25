#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int val) : val(val), left(NULL), right(NULL) {}
	};
public:
	//（1）层次遍历二叉树；
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		vector<vector<int>> result;
		
		if (root) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		result.push_back(vec);
		}
		
	return result;
	}
	
	//（2）按满二叉树方式建立二叉树；
	void createTree(TreeNode* root, int arr[], int i, int n) {
		if (i < n) {
			TreeNode* newNode = new TreeNode(arr[i]);
			root = newNode;
			
			createTree(root->left, arr, 2*i+1, n);
			createTree(root->right, arr, 2*i+2, n);	
		}
	}
	
	//（3）按先序遍历方式建立二叉树；
	void createdTree(TreeNode*& root) {
		int val;
		cin >> val;
		
		if (val == -1) {
			root = NULL;
			return;
		}
		root = new TreeNode(val);

		createdTree(root->left);
		createdTree(root->right);
	}

	//（4）求二叉树的叶子结点数；
	int getCount(TreeNode* root) {
		queue<TreeNode*> que;
		int count = 0;
		
		if (root) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			count += size;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return count;
	}
	
	//（5）求二叉树的深度
	int getDepthMax(TreeNode* root) {
		queue<TreeNode*> que;
		int depth = 0;
		
		if (root) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
	return depth;
	}
	
	int getDepthMin(TreeNode* root) {
		queue<TreeNode*> que;
		int depth = 0;
		
		if (root) que.push(root);
		while (!que.empty()) {
			int size = que.size();
			depth++;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
				if (!node->left && !node->right) return depth; 
			}
		}
		return depth;
	}
};

