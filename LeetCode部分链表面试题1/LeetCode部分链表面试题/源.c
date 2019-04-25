//��Щ��Ŀ���Ѿ���LeetCode�ϱ������ͨ����,����ֻ�����еĴ���,û��ͷ�ļ��Լ���������

struct ListNode {
	int val;
	struct ListNode *next;
};

//1.ɾ�������е��ڸ���ֵ val �����нڵ㡣
struct ListNode* removeElements(struct ListNode* head, int val) {
	//����Ϊ��
	if (head == NULL)
		return head;
	//����Ϊ��
	//Ϊ�˷�ֹɾ���������ǵ�һ���ڵ�,���Դ���һ���ٽڵ���Ϊͷ�ڵ�
	struct ListNode* faker = (struct ListNode*)malloc(sizeof(struct ListNode));
	faker->next = head;
	faker->val = 0;
	struct ListNode* cur = faker;
	while (cur != NULL)
	{
		if (cur->next != NULL && cur->next->val == val)
		{
			struct ListNode* tmp = cur->next;
			cur->next = tmp->next;
			free(tmp);
		}
		else
			cur = cur->next;
	}
	head = faker->next;
	free(faker);
	return head;
}

//2.��תһ��������(�ǵݹ鷽��)
struct ListNode* reverseList(struct ListNode* head) {
	//����Ϊ��
	if (head == NULL)
		return head;
	//����Ϊ��
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		struct ListNode* tmp = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = tmp;
	}
	return newhead;
}

//3.��תһ��������(�ݹ鷽��)
struct ListNode* reverseList(struct ListNode* head) {
	//��Ҫ��תһ���ڵ�Ҫ��֤����������в����Ѿ���ת��
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* cur = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return cur;
}

//4.����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
struct ListNode* middleNode(struct ListNode* head) {
	if (head == NULL)
		return head;
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//5. ����һ����������������е�����k�����
struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL)
		return NULL;
	struct ListNode* front = pListHead;
	struct ListNode* back = pListHead;
	int i = 0;
	for (i = 0; front != NULL && i < k; i++)
		front = front->next;
	if (i < k)
		return NULL;
	while (front != NULL)
	{
		front = front->next;
		back = back->next;
	}
	return back;
}

//6.��������������ϲ�Ϊһ���µ������������ء�(�ǵݹ�)
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode* tmp1 = l1;
	struct ListNode* tmp2 = l2;
	struct ListNode* head = NULL;
	struct ListNode* cur=NULL;
	while (tmp1 != NULL && tmp2 != NULL)
	{
		if (tmp1->val < tmp2->val)
		{
			if (cur == NULL)
				head = cur = tmp1;
			else
			{
				cur->next = tmp1;
				cur = tmp1;
			}
			tmp1 = tmp1->next;
		}
		else
		{
			if (cur == NULL)
				head = cur = tmp2;
			else
			{
				cur->next = tmp2;
				cur = tmp2;
			}
			tmp2 = tmp2->next;
		}
	}
	if (tmp1 == NULL)
		cur->next = tmp2;
	else
		cur->next = tmp1;
	return head;
}

//7.��������������ϲ�Ϊһ���µ������������ء�(�ݹ�)
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

//8.��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ��,
//�ظ��Ľ�㲻��������������ͷָ��
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	//������
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	//���������������ڵ�,Ϊ�˷�ֹҪɾ�������ݾ��ǵ�һ���ڵ�,���Դ���һ���ٽڵ���Ϊͷ�ڵ�
	struct ListNode* faker = (struct ListNode*)malloc(sizeof(struct ListNode));
	faker->next = pHead;
	struct ListNode* pre = faker;
	struct ListNode* p1 = pHead;
	struct ListNode* p2 = pHead->next;
	while (p2 != NULL)
	{
		if (p1->val != p2->val)
		{
			pre = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL && p2->val == p1->val)
				p2 = p2->next;
			while (p1 != p2)
			{
				struct ListNode* cur = p1;
				p1 = p1->next;
				free(cur);
			}
			pre->next = p2;
			if (p2 != NULL)
				p2 = p2->next;
		}
	}
	pHead = faker->next;
	free(faker);
	return pHead;
}
