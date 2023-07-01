#include <bits/stdc++.h>
#include <ctime>

using namespace std;

// 冒泡排序
void bubbleSort(vector<int>& arr, int& comparisons, int& moves) {
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			comparisons++;
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				moves += 3; // 交换3次移动
			}
		}
	}
}

// 直接插入排序
void insertionSort(vector<int>& arr, int& comparisons, int& moves) {
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		comparisons++;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			moves++;
			j--;
		}
		arr[j + 1] = key;
		moves++;
	}
}

// 简单选择排序
void selectionSort(vector<int>& arr, int& comparisons, int& moves) {
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			comparisons++;
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
		moves += 3; 
	}
}

// 快速排序
void quickSort(vector<int>& arr, int left, int right, int& comparisons, int& moves) {
	if (left < right) {
		int pivot = arr[right];
		int i = left - 1;
		for (int j = left; j <= right - 1; j++) {
			comparisons++;
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);
				moves += 3; 
			}
		}
		swap(arr[i + 1], arr[right]);
		moves += 3; 
		
		int partitionIndex = i + 1;
		
		quickSort(arr, left, partitionIndex - 1, comparisons, moves);
		quickSort(arr, partitionIndex + 1, right, comparisons, moves);
	}
}

// 希尔排序
void shellSort(vector<int>& arr, int& comparisons, int& moves) {
	int n = arr.size();
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j = i;
			comparisons++;
			while (j >= gap && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				moves++;
				j -= gap;
			}
			arr[j] = temp;
			moves++;
		}
	}
}

// 堆排序
void heapify(vector<int>& arr, int n, int i, int& comparisons, int& moves) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	comparisons += 2; // 比较左右子节点
	
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}
	
	if (largest != i) {
		swap(arr[i], arr[largest]);
		moves += 3; // 交换3次移动
		
		heapify(arr, n, largest, comparisons, moves);
	}
}

void heapSort(vector<int>& arr, int& comparisons, int& moves) {
	int n = arr.size();
	
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i, comparisons, moves);
	}
	
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		moves += 3; // 交换3次移动
		
		heapify(arr, i, 0, comparisons, moves);
	}
}

// 生成随机数据
vector<int> generateRandomData(int length) {
	vector<int> data(length);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 1000);
	
	for (int i = 0; i < length; i++) {
		data[i] = dis(gen);
	}
	
	return data;
}

int main() {
	const int numDataSets = 5;
	const int dataSetLength = 100;
	
	for (int i = 0; i < numDataSets; i++) {
		vector<int> data = generateRandomData(dataSetLength);
		
		// 复制数据用于每个排序算法的测试
		vector<int> bubbleData = data;
		vector<int> insertionData = data;
		vector<int> selectionData = data;
		vector<int> quickData = data;
		vector<int> shellData = data;
		vector<int> heapData = data;
		
		int bubbleComparisons = 0;
		int bubbleMoves = 0;
		bubbleSort(bubbleData, bubbleComparisons, bubbleMoves);
		
		int insertionComparisons = 0;
		int insertionMoves = 0;
		insertionSort(insertionData, insertionComparisons, insertionMoves);
		
		int selectionComparisons = 0;
		int selectionMoves = 0;
		selectionSort(selectionData, selectionComparisons, selectionMoves);
		
		int quickComparisons = 0;
		int quickMoves = 0;
		quickSort(quickData, 0, quickData.size() - 1, quickComparisons, quickMoves);
		
		int shellComparisons = 0;
		int shellMoves = 0;
		shellSort(shellData, shellComparisons, shellMoves);
		
		int heapComparisons = 0;
		int heapMoves = 0;
		heapSort(heapData, heapComparisons, heapMoves);
		
		cout << "Data Set " << i + 1 << ":" << endl;
		cout << "Bubble Sort Comparisons: " << bubbleComparisons << endl;
		cout << "Bubble Sort Moves: " << bubbleMoves << endl;
		
		cout << "Insertion Sort Comparisons: " << insertionComparisons << endl;
		cout << "Insertion Sort Moves: " << insertionMoves << endl;
		
		cout << "Selection Sort Comparisons: " << selectionComparisons << endl;
		cout << "Selection Sort Moves: " << selectionMoves << endl;
		
		cout << "Quick Sort Comparisons: " << quickComparisons << endl;
		cout << "Quick Sort Moves: " << quickMoves << endl;
		
		cout << "Shell Sort Comparisons: " << shellComparisons << endl;
		cout << "Shell Sort Moves: " << shellMoves << endl;
		
		cout << "Heap Sort Comparisons: " << heapComparisons << endl;
		cout << "Heap Sort Moves: " << heapMoves << endl;
		
		cout << endl;
	}
	
	return 0;
}


