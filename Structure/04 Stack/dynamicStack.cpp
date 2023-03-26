#include<bits/stdc++.h>
#define STACK_SIZE     100 
#define STACKINCREMENT 10  
#define ERROR          -1
#define OK             1

typedef int ElemType;
typedef int Status;

typedef struct sqstack
{
	ElemType  *bottom;     
	ElemType  *top;        
	int   stacksize;       
}SqStack ;

using namespace std;


int Init_Stack(SqStack *S)
{
	S->bottom = (ElemType *)malloc(STACK_SIZE *sizeof(ElemType));
	if (!S->bottom) return ERROR;
	S->top = S->bottom;    
	S->stacksize = STACK_SIZE;
	return OK;
}

Status push(SqStack *S , ElemType  e)
{
	if(S->top-S->bottom >= S->stacksize-1)
	{
		cout << 1 << endl;
		S->bottom  = (ElemType *)realloc(S->bottom,
			(STACKINCREMENT+S->stacksize) *sizeof(ElemType));   /*  栈满，追加存储空间  */
		if (!S->bottom) return  ERROR;
		S->top =  S->bottom+S->stacksize-1;
		S->stacksize += STACKINCREMENT ;
	}
	*S->top = e; S->top++; /*  栈顶指针加1，e成为新的栈顶 */
	return OK;
}

int showStack(SqStack *S)
{
	ElemType *p;
	p = S->bottom;
	
	while(p < S->top)
	{
		printf("%d\t",*p);
		p++;
	}
	return OK;
}

Status pop( SqStack *S, ElemType  *e)
/*弹出栈顶元素*/
{
	if ( S->top== S->bottom )
		return ERROR ;       /*  栈空，返回失败标志  */
	S  -> top-- ;
	*e =  *S->top ;
	return  OK ;
}

int main() {
	return 0;
}
