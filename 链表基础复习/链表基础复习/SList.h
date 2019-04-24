#pragma once

typedef int SListDataType;

typedef struct SListNode
{
	struct SListNode* p_next;
	SListDataType data;
}SListNode;

void SListInit(SListNode** head);//�����ʼ��
void SListDestory(SListNode** head);//��������
SListNode* BuySListNode(SListDataType data);//�����½ڵ�
void SListPrint(SListNode* head);//��ӡ����
void SListPushFront(SListNode** head,SListDataType data);//ͷ��
void SListPopFront(SListNode** head);//ͷɾ
void SListPushBack(SListNode** head,SListDataType data);//β��
void SListPopBack(SListNode** head);//βɾ
void SListInsert(SListNode** pos, SListDataType data);//����λ�ò���
void SListErace(SListNode** head,SListNode* pos);//����λ��ɾ��
SListNode* SListRomve(SListNode** head, SListDataType data);//ɾ��������ֵΪdata�Ľڵ�
SListNode* SListRomveAll(SListNode** head, SListDataType data);//ɾ������������ֵΪdata������