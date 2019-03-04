#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SList.h"

//========================��Ҫ�ı������ͷָ��===========================

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
	//��ʼ��
	*pHead = NULL;
}

//pHead��pList�Ŀ���
//�����Ƿ����:NULL
//������:�����Ѿ�����,�����������޽ڵ�
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
void SListPopBack(SListNode** pHead)
{
	//βɾ
	assert(pHead != NULL);
	//1.������
	if (*pHead == NULL)
		return;
	else if ((*pHead)->_pNext==NULL)
	{
		//2.ֻ��һ���ڵ�
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		//3.�����������������ڵ�
		SListNode* pCur = *pHead;
		while (pCur->_pNext->_pNext != NULL)
			pCur = pCur->_pNext;
		free(pCur->_pNext);
		pCur->_pNext = NULL;
	}
}

void SListPushFront(SListNode** pHead, SListDateType data)
{
	//ͷ��
	assert(pHead != NULL);
	SListNode* pNewNode = BuySListNode(data);
	pNewNode->_pNext = *pHead;
	*pHead = pNewNode;
}
void SListPopFront(SListNode** pHead)
{
	//ͷɾ
	assert(pHead != NULL);
	//1.������
	if (*pHead == NULL)
		return;
	//2.������1���ڵ�
	SListNode* pDel = *pHead;
	*pHead = pDel->_pNext;
	free(pDel);
}
SListNode* SListFind(SListNode* pHead, SListDateType data)
{
	//����
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
	//����λ�ò���
	if (pos == NULL)
		return;
	SListNode* pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErace(SListNode** pHead, SListNode* pos)
{
	//����λ��ɾ��
	assert(pHead != NULL);
	if (pos == NULL || *pHead == NULL)
		return;
	if (pos == *pHead)//ɾ��������λ����ͷ��
		*pHead = pos->_pNext;
	else//ɾ����λ�ò���ͷ��
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
	//���������
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
	//�����ܹ��ж��ٸ��ڵ�
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
	//�����Ƿ�Ϊ��
	if (pHead == NULL)
		return 1;
	else
		return 0;
}
SListDateType Front(SListNode* pHead)
{
	//����ĵ�һ���ڵ��ֵ
	if (pHead == NULL)
	{
		printf("����Ϊ��,�޵�һ���ڵ�\n");
		return -1;
	}
	else
		return pHead->_data;
}
SListDateType Back(SListNode* pHead)
{
	//��������һ���ڵ��ֵ
	if (pHead == NULL)
	{
		printf("����Ϊ��,�����һ���ڵ�\n");
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
	//ɾ�������е�һ��ֵΪdata�Ľڵ�
	assert(pHead != NULL);
	SListNode* pCur = *pHead;
	if (*pHead == NULL)//�������޽ڵ�
		return;
	else
	{
		//����������һ���ڵ�
		while (pCur != NULL)
		{
			//��һ���ڵ������Ϊdata
			if ((*pHead)->_data == data)
			{
				*pHead = pCur->_pNext;
				free(pCur);
				return;
			}
			else
			{
				//data���ǵ�һ���ڵ������
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
	//ɾ������������ֵΪdata�Ľڵ�
	assert(pHead != NULL);
	SListNode* pCur = *pHead;
	if (*pHead == NULL)//�������޽ڵ�
		return;
	else
	{
		//����������һ���ڵ�
		while (pCur != NULL)
		{
			//��һ���ڵ������Ϊdata
			if ((*pHead)->_data == data)
			{
				*pHead = pCur->_pNext;
				free(pCur);
				pCur = *pHead;
			}
			else
			{
				//data���ǵ�һ���ڵ������
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
	//����ð������

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
	//��תһ��������
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

void TestList5()//����SListRemoveAll
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

void TestList4()//����SListRemove
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
	printf("�ڵ����Ϊ:%d\n", SListSize(pList));
	printf("��һ���ڵ��ֵΪ:%d\n",Front(pList));
	printf("���һ���ڵ��ֵΪ:%d\n", Back(pList));

	SListInsert(SListFind(pList, 3), 7);
	PrintSList(pList);
	printf("�ڵ����Ϊ:%d\n", SListSize(pList));
	printf("��һ���ڵ��ֵΪ:%d\n", Front(pList));
	printf("���һ���ڵ��ֵΪ:%d\n", Back(pList));

	SListErace(&pList,SListFind(pList, 3));
	PrintSList(pList);
	printf("�ڵ����Ϊ:%d\n", SListSize(pList));
	printf("��һ���ڵ��ֵΪ:%d\n", Front(pList));
	printf("���һ���ڵ��ֵΪ:%d\n", Back(pList));

	SListErace(&pList, SListFind(pList, 1));
	PrintSList(pList);
	printf("�ڵ����Ϊ:%d\n", SListSize(pList));
	printf("�����Ƿ�Ϊ��:%d\n", SListEmpty(pList));
	printf("��һ���ڵ��ֵΪ:%d\n", Front(pList));
	printf("���һ���ڵ��ֵΪ:%d\n", Back(pList));
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

	SListPopFront(&pList);//ͷɾ,������һ���ڵ�
	PrintSList(pList);

	SListPopFront(&pList);
	SListPopFront(&pList); 
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	PrintSList(pList);//ͷɾ,ֻ��һ���ڵ�

	SListPopFront(&pList);
	PrintSList(pList);//ͷɾ,�޽ڵ�
	printf("�ڵ����Ϊ:%d\n", SListSize(pList));
	printf("�����Ƿ�Ϊ��:%d\n", SListEmpty(pList));
	printf("��һ���ڵ��ֵΪ:%d\n", Front(pList));
	printf("���һ���ڵ��ֵΪ:%d\n", Back(pList));
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
	
	SListPopBack(&pList);//βɾɾ��6
	PrintSList(pList);

	SListPopBack(&pList);//βɾɾ��5,4,3,2(�����������ڵ�����)
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	PrintSList(pList);

	SListPopBack(&pList);//βɾɾ��1(ֻ��һ���ڵ�����)
	PrintSList(pList);

	SListPopBack(&pList);//ɾ���޽ڵ�����
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
