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
}SList;//第一个节点的地址放在first上.                             

//初始化
void SListInit(SList* sl)
{
	sl->first = NULL;
}

