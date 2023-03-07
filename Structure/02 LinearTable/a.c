#include <stdio.h>
#include <stdlib.h>
#define ElemSize 100
typedef int Status;
typedef int ElemType;

// ˳���ṹ�崴��
typedef struct sqlist
{
	ElemType array[ElemSize];
	int length;
}SqList;

// ˳����ʼ��
Status Init_SqList(SqList* L) {
	L->array = (ElemType*)malloc(ElemSize * sizeof(ElemType));
	if (!L->array) return -1;
	else {
		L->length = 0;
		return 1;
	}
}

// ˳���Ĳ���
Status Insert_SqList(SqList* L, int i, ElemType e) {
	if (i < 0 || i>L->length - 1) return -1;
	if (L->length >= ElemSize) printf("���");
	for (int j = L->length - 1; j >= i - 1; j--) {
		L->array[j + 1] = L->array[j];
	}
	L->array[i - 1] = e;
	L->length++;
	return 1;
}

// ��ʾ˳�������
void Show_List(SqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d", L->array[i]);
}

// ˳���ɾ������λ�ã�
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

// ˳���ɾ��������ֵ��
Status Locate_Delete_SqList(SqList* L��ElemType x)/* ɾ�����Ա�L��ֵΪx�ĵ�һ����� */
{
	int i = 0, k;
	while (i < L->length) /*����ֵΪx�ĵ�һ�����*/ {
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
// ˳������
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
