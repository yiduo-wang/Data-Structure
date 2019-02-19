#pragma once

typedef int SListDateType;

typedef struct SListNode
{
	struct SListNode* _pNext;
	SListDateType _data;
}SListNode;

//����ͷ���ĵ�����
void SListInit(SListNode** pHead);//��ʼ��
void SListPushBack(SListNode** pHead, SListDateType data);//β��
void SListPopBack(SListNode** pHead);//βɾ
void SListPushFront(SListNode** pHead, SListDateType data);//ͷ��
void SListPopFront(SListNode** pList);//ͷɾ
SListNode* SListFind(SListNode* pHead, SListDateType data);//����
void SListInsert(SListNode* pos, SListDateType data);//����λ�ò���
void SListErace(SListNode** pHead,SListNode* pos);//����λ��ɾ��
void SListDestroy(SListNode** pHead);//���������
int SListSize(SListNode* pHead);//�����ܹ��ж��ٸ��ڵ�
int SListEmpty(SListNode* pHead);//�����Ƿ�Ϊ��
SListDateType Front(SListNode* pHead);//����ĵ�һ���ڵ��ֵ
SListDateType Back(SListNode* pHead);//��������һ���ڵ��ֵ
void SListRemove(SListNode** pHead,SListDateType data);//ɾ��������ֵΪdata�Ľڵ�
void SListRemoveAll(SListNode** pHead, SListDateType data);//ɾ�����������нڵ�
void SListBubbleSort(SListNode* pHead);//����ð������
void TestList();
