#pragma once
//链表的特点:
//1.要操作某一个节点,往往需要找到这个节点的上一个节点(前驱节点)
//2.操作第一个节点往往要特殊处理
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

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

void SListPushFront(SList* sl,SListDateType data )
{
	//头插
	assert(sl->first != NULL);
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = sl->first;
	sl->first = newnode;
	newnode->value = data;
}

void SListPopFront(SList* sl)
{
	//头删
	assert(sl->first != NULL);
	Node* second = sl->first->next;
	free(sl->first);
	sl->first = second;
}

void SListPushBack(SList* sl, SListDateType data)
{
	//尾插
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->value = data;
	newnode->next = NULL;
	//链表无节点
	if (sl->first == NULL)
		sl->first = newnode;
	//链表至少有一个节点
	Node* p = sl->first;
	while (p->next != NULL)
		p = p->next;
	p->next = newnode;
}

void SListPopBack(SList* sl)
{
	//尾删
	//链表无节点
	if (sl->first == NULL)
		return;
	//链表只有一个节点
	if (sl->first->next == NULL)
	{
		free(sl->first);
		sl->first = NULL;
		return;
	}
	//链表至少有两个节点
	Node* p = sl->first;
	while (p->next->next != NULL)
		p = p->next;
	free(p->next);
	p->next = NULL;
}

void SListRemove(SList* sl, SListDateType data)
{
	Node* cur = sl->first;
	//第一个节点的值就是data
	if (sl->first->value == data)
	{
		free(sl->first);
		sl->first = cur->next;
		return;
	}
	//data不在第一个节点上
	else
	{
		while (cur->next != NULL)
		{
			if (cur->next->value == data)
			{
				Node* next = cur->next;
				cur->next = cur->next->next;
				free(next);
				return;
			}
			cur = cur->next;
		}
	}
}

void SListRemoveAll(SList* sl, SListDateType data)
{
	Node* cur = sl->first;
	while (cur->next != NULL)
	{
		if (cur->next->value == data)
		{
			Node* next = cur->next;
			cur->next = cur->next->next;
			free(next);
		}
		else
			cur=cur->next;
	}
	//检查头是否为data
	if (sl->first->value == data)
	{
		Node* first = sl->first;
		sl->first = sl->first->next;
		free(first);
	}
}

