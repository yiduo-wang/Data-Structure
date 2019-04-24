#pragma once

typedef int SListDataType;

typedef struct SListNode
{
	struct SListNode* p_next;
	SListDataType data;
}SListNode;

void SListInit(SListNode** head);//链表初始化
void SListDestory(SListNode** head);//链表销毁
SListNode* BuySListNode(SListDataType data);//创建新节点
void SListPrint(SListNode* head);//打印链表
void SListPushFront(SListNode** head,SListDataType data);//头插
void SListPopFront(SListNode** head);//头删
void SListPushBack(SListNode** head,SListDataType data);//尾插
void SListPopBack(SListNode** head);//尾删
void SListInsert(SListNode** pos, SListDataType data);//任意位置插入
void SListErace(SListNode** head,SListNode* pos);//任意位置删除
SListNode* SListRomve(SListNode** head, SListDataType data);//删除链表中值为data的节点
SListNode* SListRomveAll(SListNode** head, SListDataType data);//删除链表中所有值为data的数据