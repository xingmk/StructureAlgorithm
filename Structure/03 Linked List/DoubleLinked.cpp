#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
public:
	// 结构体定义
struct DoubleLinked {
	int val;
	DoubleLinked *next;
	DoubleLinked *prev;
	DoubleLinked (int val):val(val), next(nullptr), prev(nullptr) {}
};
	// 初始化链表
	MyLinkedList() {
		_dummyHead = new DoubleLinked(0);
		_size = 0;
	}
	// 
	// 双向链表的插入
void doubleLinkedInsert(int index,int val) {	
	if (index > _size) return;
	if (index < 0) index = 0;
	DoubleLinked *newNode = new DoubleLinked(val);
	DoubleLinked *cur = _dummyHead;
	while (index--) {
		cur = cur->next;
	}
	
	newNode->next = cur->next;
	cur->next->prev = newNode;
	newNode->prev = cur;
	cur->next = newNode;
	_size++;
}

	// 双向链表的删除
void doubleLinkedDelete(int index) {
	if (index >= _size || index < 0) return;
	DoubleLinked *cur = _dummyHead;
	while(index--){
		cur = cur->next;
	}
	DoubleLinked *temp = cur->next;
	cur->next = cur->next->next;
	cur->next->prev = cur;                   
	delete temp;
	_size--;
	
}
private:
	int _size;
	DoubleLinked* _dummyHead;
};

int main() {
	return 0;
}
