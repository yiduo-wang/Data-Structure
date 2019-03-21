#pragma once

typedef int SLDataType;

typedef struct SqList
{
	SLDataType* arr;//��̬�����˳���ռ�
	int size;//��Ч���ݵĸ���
	int capacity;//����Ŀռ������
}SqList;

void SqListInit(SqList* sql, int capacity);//��ʼ��
void SqListDestory(SqList* sql);//����
void CheckCapacity(SqList* sql);//�ж��Ƿ�����
void SqListPrint(SqList* sql);//��ӡ˳���
void SqListPushBack(SqList* sql,SLDataType data);//β��
void SqListPopBack(SqList* sql);//βɾ
void SqListPushFront(SqList* sql,SLDataType data);//ͷ��
void SqListPopFront(SqList* sql);//ͷɾ
void SqListInsert(SqList* sql, int pos, SLDataType data);//ָ��λ�ò���
void SqListErase(SqList* sql, int pos);//ָ��λ��ɾ��
int SqListFind(SqList* sql, SLDataType data);//����data�Ƿ���˳�����
void SqListModify(SqList* sql, int pos, SLDataType data);//���±�Ϊpos�����ݸ�Ϊdata
void SqListRemove(SqList* sql, SLDataType data);//ɾ�������ĵ�һ��ָ����date
void SqListRemoveALL(SqList* sql, SLDataType data);//ɾ������������data
void SqListBubbleSort(SqList* sql);//˳���ð������
int SqListBinaryFind(SqList* sql, SLDataType data);//˳���Ķ��ֲ���