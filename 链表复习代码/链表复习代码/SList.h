#pragma once
#include<stdio.h>

typedef int SListDateType;
typedef struct Node
{
	SListDateType value;
	struct Node* next;
}Node;

typedef struct SList
{
	Node* first;
}SList;//��һ���ڵ�ĵ�ַ����first��.                             

//��ʼ��
void SListInit(SList* sl)
{
	sl->first = NULL;
}

