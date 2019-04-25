//这些题目都已经在LeetCode上编译测试通过了,所以只有运行的代码,没有头文件以及测试用例

struct ListNode {
	int val;
	struct ListNode *next;
};

//1.删除链表中等于给定值 val 的所有节点。
struct ListNode* removeElements(struct ListNode* head, int val) {
	//链表为空
	if (head == NULL)
		return head;
	//链表不为空
	//为了防止删除的数据是第一个节点,所以创建一个假节点作为头节点
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

//2.反转一个单链表(非递归方法)
struct ListNode* reverseList(struct ListNode* head) {
	//链表为空
	if (head == NULL)
		return head;
	//链表不为空
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

//3.反转一个单链表(递归方法)
struct ListNode* reverseList(struct ListNode* head) {
	//你要反转一个节点要保证它后面的所有部分已经反转了
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* cur = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return cur;
}

//4.给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
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

//5. 输入一个链表，输出该链表中倒数第k个结点
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

//6.将两个有序链表合并为一个新的有序链表并返回。(非递归)
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

//7.将两个有序链表合并为一个新的有序链表并返回。(递归)
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

//8.在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点,
//重复的结点不保留，返回链表头指针
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	//空链表
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	//链表至少有两个节点,为了防止要删除的数据就是第一个节点,所以创建一个假节点作为头节点
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
