#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* array;//ָ��ʵ��malloc�Ŀռ�,�ڶ���
	int size;      //˳�����������Ч�ĸ���
	int capacity;  //malloc�ռ������
}SeqList;

//��װ�Ľӿ�(��ʼ���ӿ�,���ٽӿ�)

void SeqListInit(SeqList* psl,int capacity)
{
	//��ʼ��
	assert(psl != NULL);
	psl->size = 0;//˳�������Ч����Ϊ0
	psl->capacity = capacity;//��������ֵ
	psl->array = (SLDateType*)malloc(capacity * sizeof(SLDateType));
	//����һ�������������ݵ�����
	if (psl->array == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
}

void CheckCapacity(SeqList* spl)
{
	//����
	assert(spl != NULL);
	if (spl->size <= spl->capacity)
		spl->array = (SLDateType*)realloc(spl->array, 50);
}

void SeqListDestroy(SeqList* psl)
{
	//����,�Ƚ��ȳ�,��һ�л�ԭ
	assert(psl != NULL);//
	free(psl->array);
	psl->array = NULL;
	psl->capacity = 0;
	psl->size = 0;
}

//������ɾ��Ľӿ�
void SeqListPushBack(SeqList* psl, SLDateType data)
{
	//β��,������˳���β��
	assert(psl != NULL);
	//����Ƿ���Ҫ����
	CheckCapacity(psl);
	psl->array[psl->size] = data;
	++psl->size;
}

void SeqListPopBack(SeqList* psl)
{
	//βɾ,ɾ��˳���β��������
	assert(psl != NULL);
	if (psl->size == 0)
		return;
	--psl->size;

}

void SeqListPushFront(SeqList*psl, SLDateType data)
{
	//ͷ��,������˳����ͷ��,�±�Ϊ[0]��λ��
	assert(psl != NULL);
	//����Ƿ���Ҫ����
	CheckCapacity(psl);
	++psl->size;
	int i = psl->size-1;
	for (; i >= 1 ; --i)
		psl->array[i + 1] = psl->array[i];
	//�����һ�����ݿ�ʼÿ���������Ų��һλ
	psl->array[0] = data;
}

void SeqListPopFront(SeqList* spl)
{
	//ͷɾ,�ӵڶ������ݿ�ʼÿ��������ǰŲ��һλ
	assert(spl != NULL);
	int i = 1;
	for (i = 1; i < spl->size; ++i)
		spl->array[i - 1] = spl->array[i];
	--spl->size;
}
void SeqListInsert(SeqList* spl, size_t pos, SLDateType data)
{
	//��pos���ڵ��±������ݲ���
	assert(spl != NULL);
	CheckCapacity(spl);
	//pos��Ч��Χ
	assert(pos >= 0 && pos <= spl->size);
	for (int i = spl->size-1; i > (int)pos; --i)
		spl->array[i + 1] = spl->array[i];
	spl->array[pos] = data;
	++spl->size;
}

void SeqListErase(SeqList* spl, size_t pos)
{
	//��pos���ڵ��±�ɾ��
	assert(spl != NULL);
	assert(spl->size > 0);
	aessert(pos >= 0 && pos < spl->size);
	for (int i = pos + 1; i < spl->size; ++i)
		spl->array[i - 1] = spl->array[i];
	--spl->size;
}

int SeqListFind(SeqList* spl,SLDateType data)
{
	//����,�Ҵ�0��ʼ�ĵĵ�һ��(�������ظ���),�ҵ��˷����±�,û�ҵ�����-1
	assert(spl!=NULL);
	for (int i = 0; i < spl->size; ++i)
	{
		if (spl->array[i] == data)
			return i;
	}
	return -1;
}

void SeqListRemove(SeqList* spl, SLDateType data)
{
	//ɾ�������ĵ�һ��data
	assert(spl!=NULL);
	int pos = SeqListFind(spl, data);
	if (pos != -1)
		SeqListErase(spl, pos);
}

void SeqListModify(SeqList* spl, size_t pos,SLDateType*data)
{
	//�޸�pos���ڵ��±������
	assert(spl != NULL);
	aeesrt(pos >= 0 && pos < spl->size);
	spl->array[pos] = data;
}

void SeqListPrint(SeqList* psl)
{
	//��ӡ
	assert(psl != NULL);
	int i = 0;
	for (i = 0; i < psl->size; ++i)
		printf("%d ", psl->array[i]);
	printf("\n");
}


int main()
{
	SeqList psl;
	int capacity=20;
	SeqListInit(&psl,capacity);
	system("pause");
}