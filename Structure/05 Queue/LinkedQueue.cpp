#include <bits/stdc++.h>
#define ElemType int

using namespace std;

class Solution {
public:
	// 链队列的结构体定义
	typedef struct Q_node {
		ElemType data ;
		struct Qnode *next ;
	}QNode;
	typedef struct link_queue {
		QNode *front , *rear ;
	}LinkQueue ;
	
	// 链队列的初始化
	LinkQueue *Init_LinkQueue(void) { 
		QNode *q;
		LinkQueue *Q; 
		q = (QNode *) malloc (sizeof(QNode)); 
		q->next = NULL ;
		Q = (LinkQueue *) malloc (sizeof(LinkQueue));
		Q->front = Q->rear = q;
		
		return Q;
	}
	
	// 链队列的入队操作
	int push(LinkQueue *Q , ElemType e) { 
		QNode *q;
		q = (QNode *)malloc(sizeof(QNode)) ;
		if (!q) return -1;
		q->data = e; 
		q->next = NULL;
		Q->rear->next = q; 
		Q->rear = q; 
		
		return 1;
	}
	
	// 链队列的出队操作
	int pop(LinkQueue *Q, ElemType *x) { 
		QNode *q;
		if (Q->front==Q->rear) return -1;
		q = Q->front->next;
		*x = q->data;
		Q->front->next=q->next; 
		if (q == Q->rear) Q->rear = Q->front;
		
		free(q) ;
		
		return 1;
	}
};

int main() {
	
	return 0;
}
