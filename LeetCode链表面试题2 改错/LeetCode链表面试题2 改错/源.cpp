//��Щ��Ŀ���Ѿ���LeetCode�ϱ������ͨ����, ����ֻ�����еĴ���, û��ͷ�ļ��Լ���������

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

//�ж������Ƿ����
struct ListNode* reverse(struct ListNode* head)
{
	if (head == NULL)
		return NULL;
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

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL || A->next == NULL)
			return true;
		struct ListNode* fast = A;
		struct ListNode* slow = A;
		while (fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = reverse(slow->next);
		slow->next = NULL;
		struct ListNode* cur = A;
		while (cur != NULL && fast != NULL)
		{
			if (cur->val != fast->val)
				return false;
			cur = cur->next;
			fast = fast->next;
		}
		if (cur == NULL && fast == NULL)
			return true;
		return false;
	}
};

//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
int length(struct ListNode* head)
{
	int count = 0;
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		count += 1;
		cur = cur->next;
	}
	return count;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL)
		return NULL;
	if (headB == NULL)
		return NULL;
	int count_A = length(headA);
	int count_B = length(headB);
	struct ListNode* cur_A = headA;
	struct ListNode* cur_B = headB;
	if (count_A > count_B)
	{
		int count = count_A - count_B;
		while (count--)
			cur_A = cur_A->next;
	}
	else
	{
		int count = count_B - count_A;
		while (count--)
			cur_B = cur_B->next;
	}
	while (cur_A != NULL && cur_B != NULL)
	{
		if (cur_A == cur_B)
			return cur_A;
		cur_A = cur_A->next;
		cur_B = cur_B->next;
	}
	return NULL;
}

//����һ�������ж��������Ƿ��л�
bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return NULL;
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
	}
	return NULL;
}

//��������ĸ���
Node* copyRandomList(Node* head) {
	if (head == NULL)
		return NULL;
	Node* cur = head;
	while (cur != NULL)
	{
		Node* next = cur->next;
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->val = cur->val;
		newnode->next = next;
		cur->next = newnode;
		cur = next;
	}
	cur = head;
	while (cur != NULL)
	{
		Node* newnode = cur->next;
		if (cur->random == NULL)
			newnode->random = NULL;
		else
			newnode->random = cur->random->next;
		cur = newnode->next;
	}
	cur = head;
	Node* newhead = head->next;
	while (cur != NULL)
	{
		Node* newnode = cur->next;
		cur->next = newnode->next;
		if (newnode->next != NULL)
			newnode->next = newnode->next->next;
		cur = cur->next;
	}
	return newhead;
}