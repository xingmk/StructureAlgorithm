#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 100;
template <typename T>

class Solution {
private:
	int *queue;
	int head;
	int tail;
	int capacity;

public:
	void InitQueue() {
		queue = new int[MAXSIZE];
		head = tail = 0;
		capacity = MAXSIZE;
	}

	bool push(T& item) {
		if ((tail + 1) % capacity == head) return false;
		queue[tail] = item;
		tail = (tail + 1) % capacity;
		capacity++;
		
		return true;
	}
	
	bool pop(T& item) {
		if (head + 1 == tail) return false;
		item = queue[head+1];
		head = (head + 1) % capacity;
		capacity--;
		
		return true;
	}
};


int main() {
	return 0;
}
