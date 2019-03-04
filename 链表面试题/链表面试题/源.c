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
	//β��
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
	//��תһ��������
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

	assert(pHead != NULL);//����ͷ�巴ת
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
	//�����м�ڵ�,���������,�򷵻صڶ����м�ڵ�,ֻ�ܱ���һ��
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
	//�������ĵ�����K���ڵ�
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
	//�ϲ��������������
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
	//if......elseҲ���Եȼ���
	//SListNode Node;
	//pNewList=pNewHead = &Node;
	//����˵���Լ�������һ����ͷ��������,���Է���ֵ����ӵڶ����ڵ㿪ʼ����
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
	//����һ����,Ҫ������ָ�����������,С�ڲ��ֺʹ��ڵ��ڲ���
	assert(pHead != NULL);
	SListNode* Cur = pHead;
	SListNode LessNode;//���xС����
	SListNode GreatNode;//���x�����
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
	//ɾ�����ź�����������ͬ����
	assert(pHead != NULL);
	if (*pHead == NULL || (*pHead)->_pNext == NULL)
		return *pHead;
	SListNode* pPre = *pHead;
	SListNode* pCur = *pHead;
	SListNode* pFirst = NULL;
	SListNode* pLast = NULL;
	while (pCur != NULL)
	{
		//���ظ��ڵ�����
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
		//��[pFirst,pLast)������û���ҵ��ظ���
		if (pFirst->_pNext == pLast)
		{
			pPre = pCur;
			pCur = pLast;
		}
		else
		{
			//��ͷ���ҵ��ظ���
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
				//���������ҵ��ظ���
				SListNode* pDel = pFirst;
				while (pFirst != pLast)
				{
					pFirst = pFirst->_pNext;
					free(pDel);
					pDel = pFirst;
				}
				pPre->_pNext = pLast;//��ɾ�����ֵ�ǰ��ͺ�����������
			}
			pCur = pLast;//pCur��ʱ���ͷŵ����һ��������,����Ҫ�������¸�ֵ
		}
	}
	return *pHead;
}

int IsSymtric1(SListNode* pHead)
{
	if (pHead == NULL)//������Ҳ����Ľṹ
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
		//��������ÿ���ڵ�����ݷŵ�������
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
		//���м��
		pFast = pFast->_pNext->_pNext;
		pPre = pSlow;
		pSlow = pSlow->_pNext;
	}
	pPre->_pNext = NULL;//��ǰ�벿���ó�һ������
	pSlow=ReverseList(&pSlow);
	SListNode* l1 = *pHead;
	SListNode* l2 = pSlow;//���ú�벿������
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