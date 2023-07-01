#include <bits/stdc++.h>
#include <ctime>
using namespace std;

// 顺序查找
int sequentialSearch(const vector<int>& arr, int target) {
	int comparisons = 0;
	for (unsigned int i = 0; i < arr.size(); i++) {
		comparisons++;
		if (arr[i] == target)
			return comparisons;
	}
	return comparisons;
}

// 折半查找 
int binarySearch(const vector<int>& arr, int target) {
	int comparisons = 0;
	int lo = 0;
	int hi = arr.size() - 1;
	while (lo <= hi) {
		comparisons++;
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] == target) {
			return comparisons;
		} else if (arr[mid] < target) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return comparisons;
}

// 分块查找
int blockSearch(const vector<int>& arr, int target) {
	int comparisons = 0;
	int blockSize = sqrt(arr.size());
	int blockIndex = -1;
	
	for (unsigned int i = 0; i < arr.size(); i += blockSize) {
		comparisons++;
		if (arr[i] > target) {
			blockIndex = (i - blockSize) / blockSize;
			break;
		}
	}
	
	for (int i = blockIndex * blockSize; i < min((blockIndex + 1) * blockSize, int(arr.size())); i++) {
		comparisons++;
		if (arr[i] == target)
			return comparisons;
	}
	return comparisons;
}

// 插值查找
int interpolationSearch(const vector<int>& arr, int target) {
	int comparisons = 0;
	int lo = 0;
	int hi = arr.size() - 1;
	
	while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
		comparisons++;
		
		int pos = lo + ((target - arr[lo]) * (hi - lo)) / (arr[hi] - arr[lo]);
		
		if (arr[pos] == target)
			return comparisons;
		
		if (arr[pos] < target)
			lo = pos + 1;
		else
			hi = pos - 1;
	}
	return comparisons;  
}

// 获取斐波那契数列
vector<int> getFibonacciSequence(int n) {
	vector<int> fibonacci;
	fibonacci.push_back(0);
	fibonacci.push_back(1);
	
	while (fibonacci.back() < n) {
		int next = fibonacci[fibonacci.size() - 1] + fibonacci[fibonacci.size() - 2];
		fibonacci.push_back(next);
	}
	
	return fibonacci;
}

// 斐波那契查找
int fibonacciSearch(const vector<int>& arr, int target) {
	int comparisons = 0;
	
	// 获取斐波那契数列
	vector<int> fibonacci = getFibonacciSequence(arr.size());
	
	int fibIdx = fibonacci.size() - 1;
	int low = 0;
	int high = arr.size() - 1;
	
	while (low <= high) {
		comparisons++;
		
		int mid = low + fibonacci[fibIdx - 1] - 1;
		
		if (arr[mid] == target)
			return comparisons;
		
		if (arr[mid] < target) {
			low = mid + 1;
			fibIdx -= 2;
		} else {
			high = mid - 1;
			fibIdx -= 1;
		}
	}
	
	return -1;  // 目标值不在数组中
}

// 二叉树节点定义
struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 插入节点到二叉搜索树
TreeNode* insertNode(TreeNode* root, int value) {
	if (root == nullptr) {
		root = new TreeNode(value);
	} else if (value < root->value) {
		root->left = insertNode(root->left, value);
	} else {
		root->right = insertNode(root->right, value);
	}
	
	return root;
}

// 在二叉搜索树中查找目标值
bool binaryTreeSearch(TreeNode* root, int target) {
	if (root == nullptr) {
		return false;
	} else if (target == root->value) {
		return true;
	} else if (target < root->value) {
		return binaryTreeSearch(root->left, target);
	} else {
		return binaryTreeSearch(root->right, target);
	}
}

// 生成随机数据
vector<int> generateRandomData(int length) {
	vector<int> data(length);
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		data[i] = rand() % 1000 + 1;  // 假设数据范围在 1 到 1000 之间
	}
	return data;
}

int main() {
	const int numDataSets = 5;
	const int dataSetLength = 100;
	
	for (int i = 0; i < numDataSets; i++) {
		vector<int> data = generateRandomData(dataSetLength);
		int target = data[dataSetLength - 1];  // 假设目标值为最后一个元素
		
		int sequentialComparisons = sequentialSearch(data, target);
		int binaryComparisons = binarySearch(data, target);
		int blockComparisons = blockSearch(data, target);
		int interpolationComparisons = interpolationSearch(data, target);
		int fibonacciComparisons = fibonacciSearch(data, target);
		// 构建二叉搜索树
		TreeNode* root = nullptr;
		for (int j = 0; j < dataSetLength; j++) {
			root = insertNode(root, data[j]);
		}
		bool binaryTreeResult = binaryTreeSearch(root, target);
		
		cout << "Data Set " << i + 1 << ":" << endl;
		cout << "Sequential Search Comparisons: " << sequentialComparisons << endl;
		cout << "Binary Search Comparisons: " << binaryComparisons << endl;
		cout << "Block Search Comparisons: " << blockComparisons << endl;
		cout << "Interpolation Search Comparisons: " << interpolationComparisons << endl;
		cout << "Fibonacci Search Comparisons: " << fibonacciComparisons << endl;
		cout << "Binary Tree Search Result: " << (binaryTreeResult ? "Found" : "Not Found") << endl;
		cout << endl;
		
		// 释放二叉搜索树的内存
		// TODO: 编写释放二叉搜索树内存的函数
	}
	
	return 0;
}

