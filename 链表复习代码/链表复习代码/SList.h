#pragma once
typedef int SLDateType;
typedef struct Node
{
	SLDateType data;
	struct Node* next;
}Node;

typedef struct SList
{
	Node* first;
}SList;

void SListInit(SList* sl);//��ʼ��
void SListDestroy(SList* sl);//����
void SListPrint(SList* sl);//��ӡ
Node* BuySListNode(SLDateType data);//����һ���½ڵ�
void SListPushFront(SList* sl, SLDateType data);//ͷ��
void SListPopFront(SList* sl);//ͷɾ
void SListPushBack(SList* sl,SLDateType data);//β��
void SListPopBack(SList* sl);//βɾ
Node* SListFind(SList* sl, SLDateType data);//����
void SListInsertAfter(Node* pos, SLDateType data);//��pos�������
void SListEraseAfter(Node* pos);//��pos��ɾ��
void SListRemove(SList* sl, SLDateType data);//ɾ�������еĵ�һ��data
void SListRemoveALL(SList* sl, SLDateType data);//ɾ�����������е�data