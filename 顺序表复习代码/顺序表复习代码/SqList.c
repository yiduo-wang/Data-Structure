#include<stdio.h>
#include"SqList.h"
#include<stdlib.h>
#include<assert.h>

void CheckCapacity(SqList* sql)
{
	//����
	assert(sql != NULL);
	if (sql->size < sql->capacity)
		return;
	int newcapacity = 2 * sql->capacity;
	SLDataType* newarr = 
		(SLDataType*)malloc(sizeof(SLDataType)*newcapacity);
	free(sql->arr);
	sql->arr = newarr;
	sql->capacity = newcapacity;
}

void SqListInit(SqList* sql, int capacity)
{
	//��ʼ��
	assert(sql != NULL);
	sql->arr = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	sql->size = 0;
	sql->capacity = capacity;
}

void SqListDestory(SqList* sql)
{
	//����
	assert(sql != NULL);
	assert(sql->arr != NULL);
	sql->size = 0;
	sql->capacity = 0;
	free(sql->arr);
	sql->arr = NULL;
}

void SqListPrint(SqList* sql)
{
	//��ӡ
	assert(sql != NULL);
	int i = 0;
	for (; i < sql->size; ++i)
		printf("%d ", sql->arr[i]);
	printf("\n");
}

void SqListPushBack(SqList* sql, SLDataType data)
{
	//β��
	assert(sql != NULL);
	CheckCapacity(sql);
	sql->arr[sql->size] = data;
	sql->size++;
}

void SqListPopBack(SqList* sql)
{
	//βɾ
	assert(sql != NULL);
	assert(sql->size > 0);
	sql->size--;
}

void SqListPushFront(SqList* sql, SLDataType data)
{
	//ͷ��
	assert(sql != NULL);
	CheckCapacity(sql);
	int i = sql->size - 1;
	for (; i >= 0; --i)
		sql->arr[i+1] = sql->arr[i];
	sql->size++;
	sql->arr[0] = data;
}

void SqListPopFront(SqList* sql)
{
	//ͷɾ
	assert(sql != NULL);
	assert(sql->size > 0);
	int i = 0;
	for (; i < sql->size - 1; ++i)
		sql->arr[i] = sql->arr[i + 1];
	sql->size--;
}

void SqListInsert(SqList* sql, int pos, SLDataType data)
{
	//����λ�ò���
	assert(sql != NULL);
	CheckCapacity(sql);
	int i = sql->size - 1;
	for (; i >= pos; --i)
		sql->arr[i + 1] = sql->arr[i];
	sql->size++;
	sql->arr[pos] = data;
}

void SqListErase(SqList* sql, int pos)
{
	//����λ��ɾ��
	assert(sql != NULL);
	assert(sql->size > 0);
	assert(pos >= 0 && pos <= sql->size - 1);
	int i = pos;
	for (; i < sql->size - 1; ++i)
		sql->arr[i] = sql->arr[i + 1];
	sql->size--;
}

int SqListFind(SqList* sql,SLDataType data)
{
	//����ָ������data
	assert(sql != NULL);
	int i = 0;
	for (; i < sql->size; ++i)
	{
		if (sql->arr[i] == data)
			return i;
	}
	return -1;
}

void SqListModify(SqList* sql, int pos, SLDataType data)
{
	assert(sql != NULL);
	assert(sql->size > 0);
	assert(pos >= 0 && pos <= sql->size - 1);
	sql->arr[pos] = data;
}

void SqListRemove(SqList* sql, SLDataType data)
{
	//ɾ�������ĵ�һ��ָ��data
	assert(sql != NULL);
	assert(sql->size > 0);
	int i=SqListFind(sql, data);
	if (i == -1)
	{
		printf("�޴�����,ɾ��ʧ��\n");
		return;
	}
	SqListErase(sql, i);
}

void SqListRemoveALL(SqList* sql, SLDataType data)
{
	//ɾ������������data
	assert(sql != NULL);
	assert(sql->size > 0);
	int j = 0;
	int i = 0;
	for (i = 0; i < sql->size - 1; ++i)
	{
		if (sql->arr[i] != data)
		{
			sql->arr[j] = sql->arr[i];
			++j;
		}
	}
	sql->size = j;
}

void SqListBubbleSort(SqList* sql)
{
	assert(sql != NULL);
	assert(sql->size > 1);
	int i = 0;
	for (; i < sql->size-1; ++i)
	{
		for (int j = sql->size - 1; j > i; --j)
		{
			if (sql->arr[j] < sql->arr[j - 1])
			{
				SLDataType tmp = sql->arr[j];
				sql->arr[j] = sql->arr[j - 1];
				sql->arr[j - 1] = tmp;
			}
		}
	}
}

int SqListBinaryFind(SqList* sql, SLDataType data)
{
	assert(sql != NULL);
	assert(sql->size > 0);
	int left = 0;
	int right = sql->size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (sql->arr[mid] < data)
			right = mid - 1;
		else if (sql->arr[mid] > data)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}