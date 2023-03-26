#include <bits/stdc++.h>

#define MAX_STACK_SIZE  100    /*  栈初始向量大小  */
#define ERROR           -1
#define OK              1

typedef int ElemType;
typedef int Status;

using namespace std;

typedef struct Stack_Node
{
	ElemType            data;
	struct Stack_Node  *next;
}Stack_Node;

Stack_Node *Init_Link_Stack()
{
	Stack_Node *top;
	top  = (Stack_Node *)malloc(sizeof(Stack_Node));
	top->next = NULL;
	return(top);
}

Status push(Stack_Node *top , ElemType e)
{
	Stack_Node *p;
	p=(Stack_Node *)malloc(sizeof(Stack_Node)) ;
	if (!p)
		return ERROR;
	/*  申请新结点失败，返回错误标志 */
	p->data = e;
	p->next = top->next;
	top->next = p;   
	return OK;
}

void showStack(Stack_Node *top)
{
	Stack_Node *p;
	p=top->next;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
}


Status pop(Stack_Node *top, ElemType *e)
/*  将栈顶元素出栈  */
{
	Stack_Node *p ;
	if (top->next==NULL )
		return ERROR;       
	p = top->next;
	*e = p->data;     
	top->next = p->next;     
	free(p);
	return OK;
}
const char OX[17] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'
};

void conversion(int n , int d)
{
	Stack_Node *top ;
	int k, e;
	top=Init_Link_Stack();
	while(n>0)
	{
		k = n%d;
		push(top, k) ;
		n = n/d;
	}
	while(top->next != NULL)     
	{
		pop(top, &e);
		printf("%c",OX[e-0]);
	}
}
int main()
{
	return 0;
}



