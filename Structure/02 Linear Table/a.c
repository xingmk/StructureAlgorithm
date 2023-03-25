#include <stdio.h>
#include <stdlib.h>
#define ElemSize 100
typedef int Status;
typedef int ElemType;

// 顺序表结构体创建
typedef struct sqlist
{
	ElemType array[ElemSize];
	int length;
}SqList;

// 顺序表初始化
Status Init_SqList(SqList* L) {
	L->array = (ElemType*)malloc(ElemSize * sizeof(ElemType));
	if (!L->array) return -1;
	else {
		L->length = 0;
		return 1;
	}
}

// 顺序表的插入
Status Insert_SqList(SqList* L, int i, ElemType e) {
	if (i < 0 || i>L->length - 1) return -1;
	if (L->length >= ElemSize) printf("溢出");
	for (int j = L->length - 1; j >= i - 1; j--) {
		L->array[j + 1] = L->array[j];
	}
	L->array[i - 1] = e;
	L->length++;
	return 1;
}

// 显示顺序表内容
void Show_List(SqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d", L->array[i]);
}

// 顺序表删除（按位置）
ElemType Delete_SqList(SqList* L, int i) {
	if (L->length == 0) {
		printf("NULL");
		return -1;
	}
	else if (i < 1 || i > L->length) {
		printf("Not Exist");
	}
	else {
		ElemType x;
		x = L->array[i - 1];
		for (int k = i; k < L->length; k++) {
			L->array[k - 1] = L->array[k];
		}
		L->length--;
		return x;
	}
}

// 顺序表删除（按数值）
Status Locate_Delete_SqList(SqList* L，ElemType x)/* 删除线性表L中值为x的第一个结点 */
{
	int i = 0, k;
	while (i < L->length) /*查找值为x的第一个结点*/ {
		if (L->array[i] != x) i++;
		else
		{
			for (k = i + 1; k < L->length; k++) {
				L->array[k - 1] = L->array[k];
				L->length--; 
				break;
			}
		}
	}
	if (i > L->length)
	{
		printf("not exist"); 
		return -1;
	}
	return 1;
}
// 顺序表查找
Status Find_SqList(SqList* L, int i) {
	return (L->array[i - 1]);
}
Status Search_SqList(SqList* L, ElemType x) {
	for (int i = 0; i < L->length; i++) {
		if (L->array[i] == x) return i;
	}
}

int main() {
	SqList L;
	L->array = (ElemType*)malloc(ElemSize * sizeof(ElemType));

	return 0;
}
