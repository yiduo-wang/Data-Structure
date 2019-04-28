//��Щ��Ŀ���Ѿ���LeetCode�ϱ������ͨ����,����ֻ�����еĴ���,û��ͷ�ļ��Լ���������

struct  {
	int val;
	struct ListNode *next;
};

//ɾ��������ֵΪval�Ľڵ�
struct ListNode* removeElements(struct ListNode* head, int val) {
	//�սڵ�
	if (head == NULL)
		return head;
	//����������һ���ڵ�,Ϊ�˷�ֹҪɾ�������ݾ��ǵ�һ���ڵ�,���Դ���һ���ٵ�ͷ���
	struct ListNode* fake = (struct ListNode*)malloc(sizeof(struct ListNode));
	fake->next = head;
	struct ListNode* cur = fake;
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
	head = fake->next;
	free(fake);
	return head;
}

//����һ����������������е�����k�����
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL)
		return pListHead;
	struct ListNode* front = pListHead;
	int i = 0;
	for (; i < k && front != NULL; ++i)
		front = front->next;
	if (i < k)
		return NULL;
	struct ListNode* back = pListHead;
	while (front != NULL)
	{
		front = front->next;
		back = back->next;
	}
	return back;
}

//��������������ϲ�Ϊһ���µ�������������
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode* head = NULL;
	struct ListNode* cur = NULL;
	struct ListNode* tmp1 = l1;
	struct ListNode* tmp2 = l2;
	while (tmp1 != NULL && tmp2 != NULL)
	{
		if (tmp1->val <= tmp2->val)
		{
			//������ĵ�һ�����������
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
			//�������һ�����������
			if (cur == NULL)
				head = cur = tmp1;
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
	if (tmp2 == NULL)
		cur->next = tmp1;
	return head;
}

//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣
ListNode* partition(ListNode* pHead, int x) {
	if (pHead == NULL)
		return NULL;
	struct ListNode* small = NULL;
	struct ListNode* small_tmp = NULL;
	struct ListNode* big = NULL;
	struct ListNode* big_tmp = NULL;
	struct ListNode* cur = pHead;
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			if (small_tmp == NULL)
				small = small_tmp = cur;
			else
			{
				small_tmp->next = cur;
				small_tmp = cur;
			}
		}
		else
		{
			if (big_tmp == NULL)
				big = big_tmp = cur;
			else
			{
				big_tmp->next = cur;
				big_tmp = cur;
			}
		}
		cur = cur->next;
	}
	if (small_tmp == NULL)
		return big;
	if (big_tmp != NULL)
		big_tmp->next = NULL;
	small_tmp->next = big;
	return small;
}