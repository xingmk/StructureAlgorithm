#include <bits/stdc++.h>

using namespace std;

class MyLinkedList {
public:
// Linked struct
struct LinkedNode {
	int val;
	LinkedNode* next;
	LinkedNode(int val):val(val), next(nullptr){}
};

// 初始化链表
MyLinkedList() {
	_dummyHead = new LinkedNode(0);
	_size = 0;
}

// 头插
void addAtHead(int val) {
	LinkedNode *newNode = new LinkedNode(val);
	newNode->next = _dummyHead->next;
	_dummyHead->next = newNode;
}
// 尾插
void addAtTail(int val) {
	LinkedNode *newNode = new LinkedNode(val);
	LinkedNode *cur = _dummyHead;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = newNode;
	_size++;
}
// 序号查找
int getIndex (int index) {
	if (index > (_size - 1) || index < 0) {
		return -1;
	}
	LinkedNode *cur = _dummyHead->next;
	while (cur--) {
		cur = cur->next;
	}
	return cur->val;
}
// 按值查找
int getVal (int val) {
	LinkedNode *cur = _dummyHead->next;
	int cou = _size;
	while (cou--){
		if (cur->val == val) break;
		cur = cur->next;
	}
	return (_size-cou);
}
// 单链表插入
void addAtIndex (int index, int val) {
	if (index > _size) return;
	if (index < 0) index = 0;
	LinkedNode *newNode = new LinkedNode(val);
	LinkedNode *cur = _dummyHead;
	while (index--) {
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
	_size++;
}
// 序号删除
void deleteAtIndex (int index) {
	if (index >= _size || index < 0) return;
	LinkedNode *cur = _dummyHead;
	while(index--){
		cur = cur->next;
	}
	LinkedNode *temp = cur->next;
	cur->next = cur->next->next;
	delete temp;
	_size--;
}
// 按值删除
void deletdAtVal (int val) {
	LinkedNode *cur = _dummyHead;
	int cou = _size;
	while(cou--){
		if (cur->next->val == val) {
			LinkedNode *temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
			_size--;
		}else{
			cur = cur->next;
		}
	}
}
// 单链表合并
LinkedNode *mergeLinkedList(LinkedNode *La, LinkedNode *Lb) {
	LinkedNode *Lc = new LinkedNode(0);
	LinkedNode *pa = La->next;
	LinkedNode *pb = Lb->next;
	LinkedNode *pc = Lc;
	while (pa != nullptr && pa != nullptr) {
		if (pa->val < pb->val) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}else if (pa->val > pb->val) {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}else {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			LinkedNode *temp;
			temp = pb;
			pb = pb->next;
			delete temp;
		}
	}
	if (pa != nullptr) {
		pc->next =pa;
		delete Lb;
	} else {
		pc->next = pb;
		delete La;
	}
	return Lc;
}
// 显示单链表
void printLinkedList() {
	LinkedNode *cur = _dummyHead;
	while (cur->next != nullptr) {
		cout << cur->next->val << endl;
		cur = cur->next;
	}
	cout << endl;
}
private:
	int _size;
	LinkedNode* _dummyHead;
};
int mian(){
	
	return 0;
}
