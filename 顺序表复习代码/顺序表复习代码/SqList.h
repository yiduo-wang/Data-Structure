#pragma once

typedef int SLDataType;

typedef struct SqList
{
	SLDataType* arr;//动态申请的顺序表空间
	int size;//有效数据的个数
	int capacity;//申请的空间的容量
}SqList;

void SqListInit(SqList* sql, int capacity);//初始化
void SqListDestory(SqList* sql);//销毁
void CheckCapacity(SqList* sql);//判断是否扩容
void SqListPrint(SqList* sql);//打印顺序表
void SqListPushBack(SqList* sql,SLDataType data);//尾插
void SqListPopBack(SqList* sql);//尾删
void SqListPushFront(SqList* sql,SLDataType data);//头插
void SqListPopFront(SqList* sql);//头删
void SqListInsert(SqList* sql, int pos, SLDataType data);//指定位置插入
void SqListErase(SqList* sql, int pos);//指定位置删除
int SqListFind(SqList* sql, SLDataType data);//查找data是否在顺序表中
void SqListModify(SqList* sql, int pos, SLDataType data);//将下标为pos的数据改为data
void SqListRemove(SqList* sql, SLDataType data);//删除遇到的第一个指定的date
void SqListRemoveALL(SqList* sql, SLDataType data);//删除遇到的所有data
void SqListBubbleSort(SqList* sql);//顺序表冒泡排序
int SqListBinaryFind(SqList* sql, SLDataType data);//顺序表的二分查找