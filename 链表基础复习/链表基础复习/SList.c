#include<stdio.h>
#include"SList.h"
#include<stdlib.h>
#include<assert.h>

void SListInit(SListNode** head)
{
	//�����ʼ��
	*head = NULL;
}

void SListDestory(SListNode** head)
{
	//��������
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
	//�����½ڵ�
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
	//��ӡ����
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
	//ͷ��
	assert(head != NULL);
	SListNode* newNode = BuySListNode(data);
	newNode->p_next = *head;
	*head = newNode;
}

void SListPopFront(SListNode** head)
{
	//ͷɾ
	assert(head != NULL);
	//�����޽ڵ�
	if (*head == NULL)
		return;
	//����������һ���ڵ�
	SListNode* cur = *head;
	*head = (*head)->p_next;
	free(cur);
}

void SListPushBack(SListNode** head,SListDataType data)
{
	//β��
	assert(head != NULL);
	SListNode* newNode = BuySListNode(data);
	//�����޽ڵ�
	if (*head == NULL)
		*head = newNode;
	//����������һ���ڵ�
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
	//βɾ
	assert(head != NULL);
	//�������޽ڵ�
	if (*head == NULL)
		return;
	//������ֻ��һ���ڵ�
	if ((*head)->p_next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	//�����������������ڵ�
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
	//����λ�ò���
	assert(pos != NULL);
	//λ��Ϊ��
	if (*pos == NULL)
		return;
	SListNode* newNode = BuySListNode(data);
	newNode->p_next = (*pos)->p_next;
	(*pos)->p_next = newNode;
}

void SListErace(SListNode** head, SListNode* pos)
{
	//����λ��ɾ��
	assert(head != NULL);
	//ɾ��λ��Ϊ��
	if (pos == NULL)
		return;
	//ɾ��λ����ͷ��
	SListNode* cur = *head;
	if (pos == *head)
	{
		*head = (*head)->p_next;
		free(cur);
	}
	//ɾ��λ�ò���ͷ��
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
	//ɾ��������ֵΪdata�Ľڵ�
	assert(head != NULL);
	//����Ϊ��
	if (*head == NULL)
		return NULL;
	//����Ϊ��
	//Ϊ�˱���Ҫɾ�������ݾ��ǵ�һ�����,���Դ���һ���ٵ�ͷ�ڵ�
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
	//����Ϊ��
	if (*head == NULL)
		return *head;
	//����Ϊ��
	//Ϊ�˷�ֹҪɾ�������ݾ��ǵ�һ���ڵ�,���Դ���һ���ٽڵ�
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