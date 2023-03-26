#include <iostream>
#define MAX_STACK_SIZE  100   
#define ERROR           -1
#define OK              1

typedef int ElemType ;
typedef int Status;

typedef struct  sqstack
{
	ElemType stack_array[MAX_STACK_SIZE] ;
	int  top;
}SqStack;


Status Init_Stack(SqStack *S)
{
	S->top = 0;
	return OK;
}

Status push(SqStack *S, ElemType  e)
{
	if  (S->top == MAX_STACK_SIZE)
		return  ERROR;            
	
	S->stack_array[S->top] = e;  
	S->top++;                    
	return OK;                    
}

int ShowStack(SqStack S)
{
	while(S.top>0)
	{
		S.top--;
		printf("%d\t",S.stack_array[S.top]);
	}
	return OK;
}


Status pop(SqStack *S, ElemType *e)
{
	if ( S->top == 0 )
		return ERROR ;      
	S->top--;
	*e = S->stack_array[S->top];
	return OK ;
}


int main()
{
	return 0;
}


