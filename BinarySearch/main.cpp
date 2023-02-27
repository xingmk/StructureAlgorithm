#include <iostream>

/*
		>= X
	> 	= (>= X) + 1
	<   = (>= X) -1
	<=  = (>= X + 1) -1
*/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// ������
	int lo=0, hi=arr.size()-1;
	
	while (lo <= hi){		// С�ڵ���  hi<lo ʱ���� 
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
	
	// ����ҿ� 
	int lo=0, hi=arr.size()-1;
	
	while (lo < hi){		// С�� ���ʱ���� 
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] < target){
			lo = mid + 1;
		}else {
			// arr[mid] >= target
			hi = mid - 1;
		}
	}
	// return hi; 			// lo hi ���Ǵ� 
	return lo;
	
	// ȫ�� 
	int lo=-1, hi=arr.size();
	
	while (lo+1 < hi){		// lo hi ����ʱ���� 
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
