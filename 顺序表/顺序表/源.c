#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* array;//指向实际malloc的空间,在堆上
	int size;      //顺序表中真正有效的个数
	int capacity;  //malloc空间的容量
}SeqList;

//封装的接口(初始化接口,销毁接口)

void SeqListInit(SeqList* psl,int capacity)
{
	//初始化
	assert(psl != NULL);
	psl->size = 0;//顺序表中有效个数为0
	psl->capacity = capacity;//给容量赋值
	psl->array = (SLDateType*)malloc(capacity * sizeof(SLDateType));
	//申请一个用来储存数据的数组
	if (psl->array == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
}

void CheckCapacity(SeqList* spl)
{
	//扩容
	assert(spl != NULL);
	if (spl->size <= spl->capacity)
		spl->array = (SLDateType*)realloc(spl->array, 50);
}

void SeqListDestroy(SeqList* psl)
{
	//销毁,先进先出,让一切还原
	assert(psl != NULL);//
	free(psl->array);
	psl->array = NULL;
	psl->capacity = 0;
	psl->size = 0;
}

//基本增删查改接口
void SeqListPushBack(SeqList* psl, SLDateType data)
{
	//尾插,插入在顺序表尾部
	assert(psl != NULL);
	//检查是否需要扩容
	CheckCapacity(psl);
	psl->array[psl->size] = data;
	++psl->size;
}

void SeqListPopBack(SeqList* psl)
{
	//尾删,删除顺序表尾部的数据
	assert(psl != NULL);
	if (psl->size == 0)
		return;
	--psl->size;

}

void SeqListPushFront(SeqList*psl, SLDateType data)
{
	//头插,插入在顺序表的头部,下标为[0]的位置
	assert(psl != NULL);
	//检查是否需要扩容
	CheckCapacity(psl);
	++psl->size;
	int i = psl->size-1;
	for (; i >= 1 ; --i)
		psl->array[i + 1] = psl->array[i];
	//从最后一个数据开始每个数据向后挪动一位
	psl->array[0] = data;
}

void SeqListPopFront(SeqList* spl)
{
	//头删,从第二个数据开始每个数据向前挪动一位
	assert(spl != NULL);
	int i = 1;
	for (i = 1; i < spl->size; ++i)
		spl->array[i - 1] = spl->array[i];
	--spl->size;
}
void SeqListInsert(SeqList* spl, size_t pos, SLDateType data)
{
	//在pos所在的下标做数据插入
	assert(spl != NULL);
	CheckCapacity(spl);
	//pos有效范围
	assert(pos >= 0 && pos <= spl->size);
	for (int i = spl->size-1; i > (int)pos; --i)
		spl->array[i + 1] = spl->array[i];
	spl->array[pos] = data;
	++spl->size;
}

void SeqListErase(SeqList* spl, size_t pos)
{
	//在pos所在的下标删除
	assert(spl != NULL);
	assert(spl->size > 0);
	aessert(pos >= 0 && pos < spl->size);
	for (int i = pos + 1; i < spl->size; ++i)
		spl->array[i - 1] = spl->array[i];
	--spl->size;
}

int SeqListFind(SeqList* spl,SLDateType data)
{
	//查找,找从0开始的的第一个(可能有重复的),找到了返回下标,没找到返回-1
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
	//删除遇到的第一个data
	assert(spl!=NULL);
	int pos = SeqListFind(spl, data);
	if (pos != -1)
		SeqListErase(spl, pos);
}

void SeqListModify(SeqList* spl, size_t pos,SLDateType*data)
{
	//修改pos所在的下标的数据
	assert(spl != NULL);
	aeesrt(pos >= 0 && pos < spl->size);
	spl->array[pos] = data;
}

void SeqListPrint(SeqList* psl)
{
	//打印
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