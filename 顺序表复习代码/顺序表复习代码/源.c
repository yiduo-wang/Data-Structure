#include"SqList.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	SqList sql;
	SqListInit(&sql, 10);
	
	SqListPushBack(&sql, 40);
	SqListPushBack(&sql, 4);
	SqListPushBack(&sql, 1);
	SqListPushBack(&sql, 2);
	SqListPushBack(&sql, 6);
	SqListPopBack(&sql);
	SqListPushFront(&sql,5);
	SqListPushFront(&sql, 7);
	SqListPushFront(&sql, 8);
	SqListPopFront(&sql);
	SqListInsert(&sql, 2, 99);
	SqListInsert(&sql, 6, 89);
	SqListErase(&sql, 6);
	//printf("%d\n",SqListFind(&sql, 99));
	//printf("%d\n", SqListFind(&sql, 66));
	SqListModify(&sql, 6, 0);
	SqListPrint(&sql);
	//SqListRemove(&sql, 5);
	//SqListRemoveALL(&sql, 5);
	SqListBubbleSort(&sql);
	SqListPrint(&sql);
	printf("%d\n", SqListBinaryFind(&sql, 7));
	//SqListPrint(&sql);
	system("pause");
}