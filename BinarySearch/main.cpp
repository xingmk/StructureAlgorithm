#include <iostream>

/*
		>= X
	> 	= (>= X) + 1
	<   = (>= X) -1
	<=  = (>= X + 1) -1
*/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// 闭区间
	int lo=0, hi=arr.size()-1;
	
	while (lo <= hi){		// 小于等于  hi<lo 时结束 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target){
			lo = mid + 1;
		}else {
			// arr[mid] >= target
			hi = mid - 1;
		}
	}
	// return hi-1; 
	return lo;
	
	// 左闭右开 
	int lo=0, hi=arr.size()-1;
	
	while (lo < hi){		// 小于 相等时结束 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target){
			lo = mid + 1;
		}else {
			// arr[mid] >= target
			hi = mid - 1;
		}
	}
	// return hi; 			// lo hi 都是答案 
	return lo;
	
	// 全开 
	int lo=-1, hi=arr.size();
	
	while (lo+1 < hi){		// lo hi 相邻时结束 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target){
			lo = mid;
		}else {
			// arr[mid] >= target
			hi = mid;
		}
	}
	return hi;

}
