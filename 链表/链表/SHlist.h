#pragma once
#include<assert.h>
#include<stdlib.h>

typedef int SHLDataType;

typedef struct SHListNode
{
	struct SHListNode* _pNext;
	SHLDataType _data;
}SHlistNode;

SHListNode* BuySHListNode(SHLDataType data)
{
	SHListNode* pNewNode = (SHListNode*)malloc(sizeof(SHListNode));
	if (pNewNode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
}

SHListNode* SHListInit()
{
	SHlistNode* pHead = BuySHListNode(0);
	pHead->_pNext = NULL;
	return pHead;
}

void SHListPushFront(SHListNode* pHead,SHLDataType data)
{
	SHListNode* pNewNode = BuySHListNode(data);
	pNewNode->_pNext = pHead->_pNext;
	pHead->_pNext = pNewNode;
}

void SHListPopFront(SHlistNode* pHead)
{
	assert(pHead != NULL);
	SHlistNode* pDel = pHead->_pNext;
	if (pDel != NULL)
	{
		pHead = pDel->_pNext;
		free(pDel);
	}
}
