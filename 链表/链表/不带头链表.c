#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SList.h"

//========================不要改变链表的头指针===========================

SListNode* BuySListNode(SListDateType data)
{
	SListNode* pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pNewNode == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void SListInit(SListNode** pHead)
{
	//初始化
	*pHead = NULL;
}

//pHead是pList的拷贝
//链表是否存在:NULL
//空链表:链表已经存在,但是链表中无节点
void SListPushBack(SListNode** pHead, SListDateType data)
{
	//尾插
	assert(pHead);
	SListNode* pNewNode = BuySListNode(data);
	if (*pHead == NULL)
		*pHead = pNewNode;
	else
	{
		SListNode* pCur = *pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;
		pCur->_pNext = pNewNode;
	}
}
void SListPopBack(SListNode** pHead)
{
	//尾删
	assert(pHead != NULL);
	//1.空链表
	if (*pHead == NULL)
		return;
	else if ((*pHead)->_pNext==NULL)
	{
		//2.只有一个节点
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		//3.链表中至少有两个节点
		SListNode* pCur = *pHead;
		while (pCur->_pNext->_pNext != NULL)
			pCur = pCur->_pNext;
		free(pCur->_pNext);
		pCur->_pNext = NULL;
	}
}

void SListPushFront(SListNode** pHead, SListDateType data)
{
	//头插
	assert(pHead != NULL);
	SListNode* pNewNode = BuySListNode(data);
	pNewNode->_pNext = *pHead;
	*pHead = pNewNode;
}
void SListPopFront(SListNode** pHead)
{
	//头删
	assert(pHead != NULL);
	//1.空链表
	if (*pHead == NULL)
		return;
	//2.至少有1个节点
	SListNode* pDel = *pHead;
	*pHead = pDel->_pNext;
	free(pDel);
}
SListNode* SListFind(SListNode* pHead, SListDateType data)
{
	//查找
	SListNode* pCur = pHead;
	while (pCur != NULL)
	{
		if (pCur->_data == data)
			return pCur;
		pCur = pCur->_pNext;
	}
	return NULL;
}

void SListInsert(SListNode* pos, SListDateType data)
{
	//任意位置插入
	if (pos == NULL)
		return;
	SListNode* pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErace(SListNode** pHead, SListNode* pos)
{
	//任意位置删除
	assert(pHead != NULL);
	if (pos == NULL || *pHead == NULL)
		return;
	if (pos == *pHead)//删除的任意位置是头部
		*pHead = pos->_pNext;
	else//删除的位置不在头部
	{
		SListNode* pre = *pHead;
		while (pre->_pNext != pos)
			pre = pre->_pNext;
		pre->_pNext = pos->_pNext;
	}
	free(pos);
}

void SListDestroy(SListNode** pHead)
{
	//链表的销毁
	SListNode* pDel = *pHead;
	while (*pHead != NULL)
	{
		pDel = *pHead;
		*pHead = pDel->_pNext;
		free(pDel);
	}
}

int SListSize(SListNode* pHead)
{
	//链表总共有多少个节点
	int count = 0;
	SListNode* pCur = pHead;
	while (pCur != NULL)
	{
		++count;
		pCur = pCur->_pNext;
	}
	return count;
}
int SListEmpty(SListNode* pHead)
{
	//链表是否为空
	if (pHead == NULL)
		return 1;
	else
		return 0;
}
SListDateType Front(SListNode* pHead)
{
	//链表的第一个节点的值
	if (pHead == NULL)
	{
		printf("链表为空,无第一个节点\n");
		return -1;
	}
	else
		return pHead->_data;
}
SListDateType Back(SListNode* pHead)
{
	//链表的最后一个节点的值
	if (pHead == NULL)
	{
		printf("链表为空,无最后一个节点\n");
		return -1;
	}
	else
	{
		SListNode* pCur = pHead;
		while (pCur->_pNext != NULL)
			pCur = pCur->_pNext;
		return pCur->_data;
	}
}

void SListRemove(SListNode** pHead, SListDateType data)
{
	//删除链表中第一个值为data的节点
	assert(pHead != NULL);
	SListNode* pCur = *pHead;
	if (*pHead == NULL)//链表中无节点
		return;
	else
	{
		//链表至少有一个节点
		while (pCur != NULL)
		{
			//第一个节点的数据为data
			if ((*pHead)->_data == data)
			{
				*pHead = pCur->_pNext;
				free(pCur);
				return;
			}
			else
			{
				//data不是第一个节点的数据
				if (pCur->_data != data)
					pCur = pCur->_pNext;
				else
				{
					SListErace(pHead, pCur);
					return;
				}
			}
		}
	}
}
void SListRemoveAll(SListNode** pHead, SListDateType data)
{
	//删除链表中所有值为data的节点
	assert(pHead != NULL);
	SListNode* pCur = *pHead;
	if (*pHead == NULL)//链表中无节点
		return;
	else
	{
		//链表至少有一个节点
		while (pCur != NULL)
		{
			//第一个节点的数据为data
			if ((*pHead)->_data == data)
			{
				*pHead = pCur->_pNext;
				free(pCur);
				pCur = *pHead;
			}
			else
			{
				//data不是第一个节点的数据
				if (pCur->_data != data)
					pCur = pCur->_pNext;
				else
				{
					SListErace(pHead, pCur);
					pCur = (*pHead)->_pNext;
				}
			}
		}
	}
}
void SListBubbleSort(SListNode* pHead)
{
	//链表冒泡排序

}

void PrintSList(SListNode* pHead)
{
	SListNode* pCur = pHead;
	while (pCur)
	{
		printf("%d->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

void ReverseList(SListNode** pHead)
{
	//反转一个单链表
	assert(pHead != NULL);
	if (*pHead == NULL)
		return;
	else
	{
		SListNode* pPre = NULL;
		SListNode* pCur = *pHead;
		SListNode* pNext = NULL;
		while (pCur != NULL)
		{
			pNext = pCur->_pNext;
			pCur->_pNext = pPre;
			pPre = pCur;
			pCur = pNext;
		}
	}
}

void TestList5()//搭配SListRemoveAll
{
	SListNode* pList = NULL;
	SListInit(&pList);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 2);
	PrintSList(pList);

	ReverseList(&pList);
	PrintSList(pList);

	SListRemoveAll(&pList, 2);
	PrintSList(pList);

}

void TestList4()//搭配SListRemove
{
	SListNode* pList = NULL;
	SListInit(&pList);
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	PrintSList(pList);

	SListRemove(&pList, 1);
	PrintSList(pList);

	SListRemove(&pList, 6);
	PrintSList(pList);
}
void TestList3()
{
	SListNode* pList = NULL;
	SListInit(&pList);
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	PrintSList(pList);
	printf("节点个数为:%d\n", SListSize(pList));
	printf("第一个节点的值为:%d\n",Front(pList));
	printf("最后一个节点的值为:%d\n", Back(pList));

	SListInsert(SListFind(pList, 3), 7);
	PrintSList(pList);
	printf("节点个数为:%d\n", SListSize(pList));
	printf("第一个节点的值为:%d\n", Front(pList));
	printf("最后一个节点的值为:%d\n", Back(pList));

	SListErace(&pList,SListFind(pList, 3));
	PrintSList(pList);
	printf("节点个数为:%d\n", SListSize(pList));
	printf("第一个节点的值为:%d\n", Front(pList));
	printf("最后一个节点的值为:%d\n", Back(pList));

	SListErace(&pList, SListFind(pList, 1));
	PrintSList(pList);
	printf("节点个数为:%d\n", SListSize(pList));
	printf("链表是否为空:%d\n", SListEmpty(pList));
	printf("第一个节点的值为:%d\n", Front(pList));
	printf("最后一个节点的值为:%d\n", Back(pList));
}

void TestList2()
{
	SListNode* pList = NULL;
	SListInit(&pList);
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	PrintSList(pList);

	SListPushFront(&pList, 0);
	PrintSList(pList);

	SListPopFront(&pList);//头删,至少有一个节点
	PrintSList(pList);

	SListPopFront(&pList);
	SListPopFront(&pList); 
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	PrintSList(pList);//头删,只有一个节点

	SListPopFront(&pList);
	PrintSList(pList);//头删,无节点
	printf("节点个数为:%d\n", SListSize(pList));
	printf("链表是否为空:%d\n", SListEmpty(pList));
	printf("第一个节点的值为:%d\n", Front(pList));
	printf("最后一个节点的值为:%d\n", Back(pList));
	SListRemove(&pList, 1);
	PrintSList(pList);
}

void TestList1()
{
	SListNode* pList=NULL;
	SListInit(&pList);
	SListPushBack(&pList, 1);	
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	PrintSList(pList);
	
	SListPopBack(&pList);//尾删删除6
	PrintSList(pList);

	SListPopBack(&pList);//尾删删除5,4,3,2(至少有两个节点的情况)
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	PrintSList(pList);

	SListPopBack(&pList);//尾删删除1(只有一个节点的情况)
	PrintSList(pList);

	SListPopBack(&pList);//删除无节点的情况
	PrintSList(pList);
}

void TestList()
{
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	TestList5();
}

int main()
{
	TestList();
	system("pause");
}
