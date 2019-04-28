//这些题目都已经在LeetCode上编译测试通过了,所以只有运行的代码,没有头文件以及测试用例

struct  {
	int val;
	struct ListNode *next;
};

//删除链表中值为val的节点
struct ListNode* removeElements(struct ListNode* head, int val) {
	//空节点
	if (head == NULL)
		return head;
	//链表至少有一个节点,为了防止要删除的数据就是第一个节点,所以创建一个假的头结点
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

//输入一个链表，输出该链表中倒数第k个结点
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

//将两个有序链表合并为一个新的有序链表并返回
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
			//新链表的第一个插入的数据
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
			//新链表第一个插入的数据
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

//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。
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