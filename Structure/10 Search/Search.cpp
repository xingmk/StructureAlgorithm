#include <bits/stdc++.h>

using namespace std;

class Solution {
	
	// 顺序查找
	bool sequenceSearch (vector<int>& nums, int target) {
		for (int num : nums) {
			if (num == target) return true;
		}
	return false;
	}
	
	// 折半查找
	bool binarySearch (vector<int>& nums, int target) {
		int lo = 0; 
		int hi = nums.size() - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return true;
			if (nums[mid] > target) hi = mid - 1;
			if (nums[mid] < target) lo = mid + 1;
		}
	return false;
	}

	// 分块查找
		typedef struct
	{
		int maxKey;     
		int address;    
	}Index;
	
	int blockSearch(vector<int> nums, Index* index, int indexLen, int key)
	{
		int lo = 0, hi = nums.size() - 1;
		int mid = lo + (hi - lo) / 2;
		
		while (lo < hi) {
			if (key == index[mid].maxKey) {
				break;
			}
			else if (key < index[mid].maxKey) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
			mid = lo + (hi - lo) / 2;
		}

		int i, start = index[mid].address, end;
	
		if (mid == indexLen - 1) {
		end = nums.size();
		} else {
		end = index[mid + 1].address;
		}
	
		for (i = start; i < end; i++) {
			if (key == nums[i]) {
				return i;
			}
		}
	return -1;
	}
	
};


int main() {
	
	vector<int> nums;
	
	return 0;
}	
