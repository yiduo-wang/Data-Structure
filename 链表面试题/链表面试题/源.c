#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int SListDateType;

typedef struct SListNode
{
	struct SListNode* _pNext;
	SListDateType _data;
}SListNode;

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

SListNode* ReverseList(SListNode** pHead)
{
	//反转一个单链表
	//assert(pHead != NULL);
	//SListNode* pPre = NULL;
	//SListNode* pCur = *pHead;
	//SListNode* pNext = NULL;
	//if (*pHead == NULL)
	//	return;
	//else
	//{
	//	while (pCur != NULL)
	//	{
	//		pNext = pCur->_pNext;
	//		pCur->_pNext = pPre;
	//		pPre = pCur;
	//		pCur = pNext;
	//	}
	//}
	//return pPre;

	assert(pHead != NULL);//利用头插反转
	SListNode* pNewHead = NULL;
	SListNode* pCur = *pHead;
	while (pCur != NULL)
	{
		*pHead = (*pHead)->_pNext;
		pCur->_pNext = pNewHead;
		pNewHead = pCur;
		pCur = *pHead;
	}
	return pNewHead;
}

SListNode* MidNode(SListNode* pHead)
{
	//返回中间节点,如果有两个,则返回第二个中间节点,只能遍历一次
	SListNode* pSlow = pHead;
	SListNode* pFast = pHead;
	while (pFast != NULL &&(pFast -> _pNext)!= NULL)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}
	return pSlow;
}

SListNode* KNode(SListNode* pHead,int k)
{
	//输出链表的倒数第K个节点
	assert(pHead != NULL);
	SListNode* pFast = pHead;
	SListNode* pSlow = pHead;
	while (k--)
	{
		assert(pFast != NULL);
		pFast = pFast->_pNext;
	}
	while (pFast != NULL)
	{
		pSlow = pSlow->_pNext;
		pFast = pFast->_pNext;
	}
	return pSlow;
}

SListNode* CmpList(SListNode** L1, SListNode** L2)
{
	//合并两个有序的链表
	SListNode* pNewList = NULL;
	SListNode* pNewHead = NULL;
	SListNode* l1 = *L1;
	SListNode* l2 = *L2;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if ((*L1)->_data <= (*L2)->_data)
	{
		pNewList =pNewHead= l1;
		l1 = l1->_pNext;
	}
	else
	{
		pNewList =pNewHead= l2;
		l2 = l2->_pNext;
	}
	//if......else也可以等价于
	//SListNode Node;
	//pNewList=pNewHead = &Node;
	//等于说是自己建立了一个有头结点的链表,所以返回值必须从第二个节点开始返回
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->_data <= l2->_data)
		{
			pNewHead->_pNext = l1;
			l1 = l1->_pNext;
		}
		else
		{
			pNewHead->_pNext = l2;
			l2 = l2->_pNext;
		}
		pNewHead = pNewHead->_pNext;
	}
	if (l1 == NULL)
		pNewHead->_pNext = l2;
	if (l2 == NULL)
		pNewHead->_pNext = l1;
	return pNewList;
	//return pNewList->_pNext;
}

SListNode* Partition(SListNode* pHead, int x)
{
	//给定一个数,要求将链表分隔成两个部分,小于部分和大于等于部分
	assert(pHead != NULL);
	SListNode* Cur = pHead;
	SListNode LessNode;//存比x小的数
	SListNode GreatNode;//存比x大的数
	SListNode* LessHead = &LessNode;
	SListNode* GreatHead = &GreatNode;
	while (Cur != NULL)
	{
		if (Cur->_data < x)
		{
			LessHead->_pNext = Cur;
			LessHead = LessHead->_pNext;
		}
		else
		{
			GreatHead->_pNext = Cur;
			GreatHead = GreatHead->_pNext;
		}
		Cur = Cur->_pNext;
	}
	LessHead->_pNext = (&GreatNode)->_pNext;
	GreatHead->_pNext = NULL;
	return LessNode._pNext;
}

SListNode* DelDuplication(SListNode** pHead)
{
	//删除掉排好序的链表的相同部分
	assert(pHead != NULL);
	if (*pHead == NULL || (*pHead)->_pNext == NULL)
		return *pHead;
	SListNode* pPre = *pHead;
	SListNode* pCur = *pHead;
	SListNode* pFirst = NULL;
	SListNode* pLast = NULL;
	while (pCur != NULL)
	{
		//找重复节点区间
		pFirst = pCur;
		pLast = pCur->_pNext;
		while (pLast != NULL)
		{
			if (pCur->_data != pLast->_data)
				break;
			else
			{
				pLast = pLast->_pNext;
				pCur = pCur->_pNext;
			}
		}
		//在[pFirst,pLast)区间内没有找到重复的
		if (pFirst->_pNext == pLast)
		{
			pPre = pCur;
			pCur = pLast;
		}
		else
		{
			//在头部找到重复的
			if (pFirst == *pHead)
			{
				while (*pHead != pLast)
				{
					*pHead = (*pHead)->_pNext;
					free(pFirst);
					pFirst = *pHead;
				}
			}
			else
			{
				//在身体里找到重复的
				SListNode* pDel = pFirst;
				while (pFirst != pLast)
				{
					pFirst = pFirst->_pNext;
					free(pDel);
					pDel = pFirst;
				}
				pPre->_pNext = pLast;//将删除部分的前面和后面连接起来
			}
			pCur = pLast;//pCur此时在释放的最后一个数据上,所以要给他重新赋值
		}
	}
	return *pHead;
}

int IsSymtric1(SListNode* pHead)
{
	if (pHead == NULL)//空链表也算回文结构
		return 1;
	int* p=malloc(sizeof(int)*900);
	if (p == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	SListNode* pCur = pHead;
	int count = 0;
	while (pCur != NULL)
	{
		//将链表中每个节点的数据放到数组中
		p[count] = pCur->_data;
		pCur = pCur->_pNext;
		++count;
	}
	int left = 0,right=count-1;
	while (left < right)
	{
		if (p[left] != p[right])
			break;
		++left;
		--right;
	}
	if (left < right)
	{
		free(p);
		return 0;
	}
	else
	{
		free(p);
		return 1;
	}

}

int IsSymtric2(SListNode** pHead)
{
	if (pHead == NULL)
		return 1;
	SListNode* pFast = *pHead;
	SListNode* pSlow = *pHead;
	SListNode* pPre = NULL;
	while (pFast != NULL && pFast->_pNext != NULL)
	{
		//找中间点
		pFast = pFast->_pNext->_pNext;
		pPre = pSlow;
		pSlow = pSlow->_pNext;
	}
	pPre->_pNext = NULL;//将前半部分置成一个链表
	pSlow=ReverseList(&pSlow);
	SListNode* l1 = *pHead;
	SListNode* l2 = pSlow;//逆置后半部分链表
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->_data != l2->_data)
			return 0;
		l1 = l1->_pNext;
		l2 = l2->_pNext;
	}
	return 1;
}

void TestList()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	//SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 3);
	//SListPushBack(&pList, 5);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 1);
	PrintSList(pList);

	printf("%d\n",IsSymtric2(&pList));
}

int main()
{
	TestList();
	system("pause");
}