#pragma once
//������ص�:
//1.Ҫ����ĳһ���ڵ�,������Ҫ�ҵ�����ڵ����һ���ڵ�(ǰ���ڵ�)
//2.������һ���ڵ�����Ҫ���⴦��
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
}SList;//��һ���ڵ�ĵ�ַ����first��.                             

//��ʼ��
void SListInit(SList* sl)
{
	sl->first = NULL;
}

void SListPushFront(SList* sl,SListDateType data )
{
	//ͷ��
	assert(sl->first != NULL);
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = sl->first;
	sl->first = newnode;
	newnode->value = data;
}

void SListPopFront(SList* sl)
{
	//ͷɾ
	assert(sl->first != NULL);
	Node* second = sl->first->next;
	free(sl->first);
	sl->first = second;
}

void SListPushBack(SList* sl, SListDateType data)
{
	//β��
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->value = data;
	newnode->next = NULL;
	//�����޽ڵ�
	if (sl->first == NULL)
		sl->first = newnode;
	//����������һ���ڵ�
	Node* p = sl->first;
	while (p->next != NULL)
		p = p->next;
	p->next = newnode;
}

void SListPopBack(SList* sl)
{
	//βɾ
	//�����޽ڵ�
	if (sl->first == NULL)
		return;
	//����ֻ��һ���ڵ�
	if (sl->first->next == NULL)
	{
		free(sl->first);
		sl->first = NULL;
		return;
	}
	//���������������ڵ�
	Node* p = sl->first;
	while (p->next->next != NULL)
		p = p->next;
	free(p->next);
	p->next = NULL;
}

void SListRemove(SList* sl, SListDateType data)
{
	Node* cur = sl->first;
	//��һ���ڵ��ֵ����data
	if (sl->first->value == data)
	{
		free(sl->first);
		sl->first = cur->next;
		return;
	}
	//data���ڵ�һ���ڵ���
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
	//���ͷ�Ƿ�Ϊdata
	if (sl->first->value == data)
	{
		Node* first = sl->first;
		sl->first = sl->first->next;
		free(first);
	}
}

