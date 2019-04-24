#include<stdio.h>
#include"SList.h"
#include<stdlib.h>
#include<assert.h>

void SListInit(SListNode** head)
{
	//链表初始化
	*head = NULL;
}

void SListDestory(SListNode** head)
{
	//链表销毁
	assert(head != NULL);
	if (*head == NULL)
		return;
	while (*head != NULL)
	{
		SListNode* cur = *head;
		*head = (*head)->p_next;
		free(cur);
	}
}

SListNode* BuySListNode(SListDataType data)
{
	//创建新节点
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	newNode->data = data;
	newNode->p_next = NULL;
	return newNode;
}

void SListPrint(SListNode* head)
{
	//打印链表
	SListNode* cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->p_next;
	}
	printf("NULL\n");
}

void SListPushFront(SListNode** head, SListDataType data)
{
	//头插
	assert(head != NULL);
	SListNode* newNode = BuySListNode(data);
	newNode->p_next = *head;
	*head = newNode;
}

void SListPopFront(SListNode** head)
{
	//头删
	assert(head != NULL);
	//链表无节点
	if (*head == NULL)
		return;
	//链表至少有一个节点
	SListNode* cur = *head;
	*head = (*head)->p_next;
	free(cur);
}

void SListPushBack(SListNode** head,SListDataType data)
{
	//尾插
	assert(head != NULL);
	SListNode* newNode = BuySListNode(data);
	//链表无节点
	if (*head == NULL)
		*head = newNode;
	//链表至少有一个节点
	else
	{
		SListNode* cur = *head;
		while (cur->p_next != NULL)
			cur = cur->p_next;
		cur->p_next = newNode;
	}
}

void SListPopBack(SListNode** head)
{
	//尾删
	assert(head != NULL);
	//链表中无节点
	if (*head == NULL)
		return;
	//链表中只有一个节点
	if ((*head)->p_next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	//链表中至少有两个节点
	else
	{
		SListNode* cur = *head;
		while (cur->p_next->p_next != NULL)
			cur = cur->p_next;
		free(cur->p_next);
		cur->p_next = NULL;
	}
}

void SListInsert(SListNode** pos, SListDataType data)
{
	//任意位置插入
	assert(pos != NULL);
	//位置为空
	if (*pos == NULL)
		return;
	SListNode* newNode = BuySListNode(data);
	newNode->p_next = (*pos)->p_next;
	(*pos)->p_next = newNode;
}

void SListErace(SListNode** head, SListNode* pos)
{
	//任意位置删除
	assert(head != NULL);
	//删除位置为空
	if (pos == NULL)
		return;
	//删除位置是头部
	SListNode* cur = *head;
	if (pos == *head)
	{
		*head = (*head)->p_next;
		free(cur);
	}
	//删除位置不在头部
	else
	{
		while (cur->p_next != pos && cur->p_next!=NULL)
			cur = cur->p_next;
		if (cur->p_next == NULL)
			return;
		cur->p_next = pos->p_next;
		free(pos);
	}
}

SListNode* SListRomve(SListNode** head, SListDataType data)
{
	//删除链表中值为data的节点
	assert(head != NULL);
	//链表为空
	if (*head == NULL)
		return NULL;
	//链表不为空
	//为了避免要删除的数据就是第一个结点,所以创建一个假的头节点
	SListNode* faker =BuySListNode(0);
	faker->p_next = *head;
	SListNode* cur = faker;
	while (cur != NULL)
	{
		if (cur->p_next->data == data)
		{
			SListNode* tmp = cur->p_next;
			cur->p_next = tmp->p_next;
			free(tmp);
			*head = faker->p_next;
			free(faker);
			return *head;
		}
		cur = cur->p_next;
	}
	*head = faker->p_next;
	free(faker);
	return *head;
}

SListNode* SListRomveAll(SListNode** head, SListDataType data)
{
	assert(head != NULL);
	//链表为空
	if (*head == NULL)
		return *head;
	//链表不为空
	//为了防止要删除的数据就是第一个节点,所以创建一个假节点
	SListNode* faker = BuySListNode(0);
	faker->p_next = *head;
	SListNode* cur = faker;
	while (cur != NULL)
	{
		if (cur->p_next!=NULL && cur->p_next->data == data)
		{
			SListNode*tmp = cur->p_next;
			cur->p_next = tmp->p_next;
			free(tmp);
		}
		else
			cur = cur->p_next;
	}
	*head = faker->p_next;
	free(faker);
	return *head;
}