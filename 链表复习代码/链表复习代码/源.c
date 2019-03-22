#include"SList.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	SList sl;
	SListInit(&sl);
	SListPushFront(&sl, 2);
	SListPushFront(&sl, 2);
	SListPushFront(&sl, 0);
	SListPushFront(&sl, 7);
	SListPushFront(&sl, 2);
	SListPushBack(&sl, 4);
	SListPushBack(&sl, 2);
	SListPrint(&sl);
	SListRemove(&sl, 2);
	SListPrint(&sl);
	SListRemoveALL(&sl, 2);
	SListPrint(&sl);
	system("pause");
}