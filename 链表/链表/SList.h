#pragma once

typedef int SListDateType;

typedef struct SListNode
{
	struct SListNode* _pNext;
	SListDateType _data;
}SListNode;

//不带头结点的单链表
void SListInit(SListNode** pHead);//初始化
void SListPushBack(SListNode** pHead, SListDateType data);//尾插
void SListPopBack(SListNode** pHead);//尾删
void SListPushFront(SListNode** pHead, SListDateType data);//头插
void SListPopFront(SListNode** pList);//头删
SListNode* SListFind(SListNode* pHead, SListDateType data);//查找
void SListInsert(SListNode* pos, SListDateType data);//任意位置插入
void SListErace(SListNode** pHead,SListNode* pos);//任意位置删除
void SListDestroy(SListNode** pHead);//链表的销毁
int SListSize(SListNode* pHead);//链表总共有多少个节点
int SListEmpty(SListNode* pHead);//链表是否为空
SListDateType Front(SListNode* pHead);//链表的第一个节点的值
SListDateType Back(SListNode* pHead);//链表的最后一个节点的值
void SListRemove(SListNode** pHead,SListDateType data);//删除链表中值为data的节点
void SListRemoveAll(SListNode** pHead, SListDateType data);//删除链表中所有节点
void SListBubbleSort(SListNode* pHead);//链表冒泡排序
void TestList();
