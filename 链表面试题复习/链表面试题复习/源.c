#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDateType;

typedef struct SListNode
{
	struct SListNode* _pNext;
	SListDateType _data;
}SListNode;

SListNode* BuySListNode(SListDateType data)
{
	SListNode* pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pNewNode == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void SListPushBack(SListNode** pHead, SListDateType data)
{
	//尾插
	assert(pHead);
	SListNode* pNewNode = BuySListNode(data);
	if (*pHead == NULL)
		*pHead = pNewNode;
	else
	{
		SListNode* pCur = *pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;
		pCur->_pNext = pNewNode;
	}
}

void PrintSList(SListNode* pHead)
{
	SListNode* pCur = pHead;
	while (pCur)
	{
		printf("%d->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

SListNode* RemoveALL(SListNode** pHead, SListDateType data)
{
	assert(pHead != NULL);
	if (*pHead == NULL)
		return NULL;
	SListNode* cur = *pHead;
	SListNode* new = NULL;
	SListNode* new_tmp = NULL;
	while (cur != NULL)
	{
		if (cur->_data != data)
		{
			if (new_tmp == NULL)
				new_tmp = new = cur;
			else
			{
				new_tmp->_pNext = cur;
				new_tmp = cur;
			}
		}
		cur = cur->_pNext;
	}
	new_tmp->_pNext = NULL;
	return new;
}

SListNode* Reverse(SListNode** pHead)
{
	assert(pHead != NULL);
	if (*pHead == NULL)
		return NULL;
	if ((*pHead)->_pNext == NULL)
		return *pHead;
	SListNode* new = NULL;
	SListNode* cur = *pHead;
	while (cur != NULL)
	{
		SListNode* next = cur->_pNext;
		cur->_pNext = new;
		new = cur;
		cur = next;
	}
	return new;
}

SListNode* FindMid(SListNode* pHead)
{
	SListNode* fast = pHead;
	SListNode* slow = pHead;
	while (fast != NULL && fast->_pNext != NULL)
	{
		fast = fast->_pNext->_pNext;
		slow = slow->_pNext;
	}
	return slow;
}

SListNode* FindK(SListNode* pHead, int k)
{
	if (pHead == NULL)
		return NULL;
	SListNode* fast = pHead;
	SListNode* slow = pHead;
	int num = 0;
	while (fast != NULL && num < k)
	{
		fast = fast->_pNext;
		++num;
	}
	if(num < k)
		return NULL;
	else
	{
		while (fast != NULL)
		{
			fast = fast->_pNext;
			slow = slow->_pNext;
		}
		return slow;
	}
}

SListNode* cat(SListNode** l1, SListNode** l2)
{
	assert(l1 != NULL && l2 != NULL);
	SListNode* new = NULL;
	SListNode* c1 = *l1;
	SListNode* c2 = *l2;
	SListNode* new_tmp = NULL;
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->_data <= c2->_data)
		{
			if (new_tmp != NULL)
			{
				new_tmp->_pNext = c1;
				new_tmp = c1;
			}
			else
				new = new_tmp = c1;
			c1 = c1->_pNext;
		}
		else
		{
			if (new_tmp != NULL)
			{
				new_tmp->_pNext = c2;
				new_tmp = c2;
			}
			else
				new = new_tmp = c2;
			c2 = c2->_pNext;
		}
	}
	if (c1 == NULL)
		new_tmp->_pNext = c2;
	else
		new_tmp->_pNext = c1;
	return new;
}

SListNode* fenge(SListNode** pHead, SListDateType data)
{
	assert(pHead != NULL);
	SListNode* cur = *pHead;
	SListNode* min = NULL;
	SListNode* min_tmp = NULL;
	SListNode* max = NULL;
	SListNode* max_tmp = NULL;
	while (cur != NULL)
	{
		if(cur->_data<=data)
		{
			if (min_tmp == NULL)
				min = min_tmp = cur;
			else
			{
				min_tmp->_pNext = cur;
				min_tmp = cur;
			}
		}
		else
		{
			if (max_tmp == NULL)
				max = max_tmp = cur;
			else
			{
				max_tmp->_pNext = cur;
				max_tmp = cur;
			}
		}
		cur = cur->_pNext;
	}
	if (min_tmp == NULL)//没有小于data的数据
		return max;
	if (max_tmp->_pNext != NULL)
		//最后一个大于data的数不在链表的末端
		//它后面还连着一个小于data的数,如果不把它的next置为空
		//它就成了一个带环的链表
		max_tmp->_pNext = NULL;
	min_tmp->_pNext = max;
	return min;
}

SListNode* DelateDuplacation(SListNode** pHead)
{
	//不相等,同时走,相等,p1不动,p2走
	//要释放p1,就要一直存着p1的前驱节点

	assert(pHead != NULL);
	if (*pHead == NULL)
		return NULL;
	SListNode* fake = (SListNode*)malloc(sizeof(SListNode));//(假节点)
	fake->_pNext = *pHead;
	SListNode* pre = fake;
	SListNode* p1 = *pHead;
	SListNode* p2 = (*pHead)->_pNext;
	while (p2 != NULL)
	{
		if (p1->_data != p2->_data)
		{
			pre = p1; 
			p1 = p2;
			p2 = p2->_pNext;
		}
		else
		{
			while (p2 != NULL && p2->_data == p1->_data)
				p2 = p2->_pNext;
			while (p1 != p2)
			{	
				SListNode* cur = p1;
				p1 = p1->_pNext;
				free(cur);
			}
			pre->_pNext = p2;
			if(p2!=NULL)
				p2 = p2->_pNext;
		}
	}
	(*pHead) = fake->_pNext;
	free(fake);
	return *pHead;
}

int main()
{
	SListNode* pHead = NULL;
	SListNode* l2 = NULL;
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 3);
	PrintSList(pHead);
	SListNode* new = IsMidNode(&pHead);
	PrintSList(new);
	system("pause");
}

Node* Copy(Node* head)
//分开三步
//第一步,只复制节点中value和next,让新节点跟在老节点后边
//第二步,处理random的复制
//第三步,把链表拆成两个
{	
	Node* cur_head = head;
	while (cur_head != NULL)
	{
		Node* newnode = (Node*)malloc(Node);
		newnode->value = cur_head->value;
		newnode->next = cur_head->next;
		cur_head->next = newnode;
		cur_head = newnode->next;
	}
	cur_head = head;
	while (cur_head != NULL)
	{
		Node* newnode = cur_head->next;
		if (cur_head->random == NULL)
			newnode->random = cur_head->random;
		else
		{
			newnode->random = cur_head->random->next;
		}
		cur_head = cur_head->next->next;
	}
	cur_head = head;
	while (cur_head != NULL)
	{
		Node* newnode = cur_head->next;
		cur_head->next = newnode->next;
		newnode->next = cur_head->next->next;
		cur_head = cur_head->next;
	}
}