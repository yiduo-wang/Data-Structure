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

void SListInit(SList* sl);//初始化
void SListDestroy(SList* sl);//销毁
void SListPrint(SList* sl);//打印
Node* BuySListNode(SLDateType data);//申请一个新节点
void SListPushFront(SList* sl, SLDateType data);//头插
void SListPopFront(SList* sl);//头删
void SListPushBack(SList* sl,SLDateType data);//尾插
void SListPopBack(SList* sl);//尾删
Node* SListFind(SList* sl, SLDateType data);//查找
void SListInsertAfter(Node* pos, SLDateType data);//在pos后面插入
void SListEraseAfter(Node* pos);//在pos后删除
void SListRemove(SList* sl, SLDateType data);//删除链表中的第一个data
void SListRemoveALL(SList* sl, SLDateType data);//删除链表中所有的data