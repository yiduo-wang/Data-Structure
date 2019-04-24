#include<stdio.h>
#include<stdlib.h>
#include"SList.h"

int main()
{
	SListNode* pList = NULL;
	SListInit(&pList);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);
	SListPrint(SListRomveAll(&pList, 4));
	system("pause");
}