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

//1.�ж������Ƿ����(���м�ڵ��ʱ���ҵ�һ��)
//���������м�ڵ��ʱ��ͱ������м�ڵ���Ŀ������ͬ
//ǰ������������ڵ��ҵ�һ��,��������������ڵ��ҵڶ���
//��������
struct ListNode* reverse(struct ListNode* head)
{
	//���������ֻ��һ���ڵ�
	if (head == NULL)
		return head;
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
		//���������ֻ��һ���ڵ�
		if (A == NULL || A->next == NULL)
			return true;
		//�����������ڵ�
		//���м�ڵ�(�����м�ڵ����ҵ�һ��)
		struct ListNode* fast = A;
		struct ListNode* slow = A;
		while (fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//��������
		fast = reverse(slow->next);
		//�м�ڵ��Ժ���Ϊ��
		slow->next = NULL;
		//1->2->3->4
		//fast:4->3->NULL    slow:1->2->NULL       �м�ڵ�:2
		//1->2->3->4->5
		//fast:5->4->NULL    slow:1->2->3->NULL    �м�ڵ�:3
		ListNode* head = A;
		while (fast != NULL && head != NULL)
		{
			if (fast->val != head->val)
				return false;
			else
			{
				fast = fast->next;
				head = head->next;
			}
		}
		if (fast == NULL && head == NULL)
			return true;
		else
			return false;
	}
};

//2.��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//������Ҫ������Ҫ�������������ʼλ�õ�����λ�õľ�����ͬ
int Length(struct ListNode* head)
{
	//����������
	struct ListNode* cur = head;
	int count = 0;
	while (cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL)
		return NULL;
	if (headB == NULL)
		return NULL;
	int count_A = Length(headA);
	int count_B = Length(headB);
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

//3.����һ�������ж��������Ƿ��л���
//Ҫ��֤fast�ߵľ�����slow�ߵľ����2��
//Ϊ�˷�ֹfast��slow��head��λ�����,��head��һ��������,
//������ѭ����ʱ��,Ҫ��slow��fast����,Ȼ�����ж�fast�Ƿ��slow���
bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

//4.����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//��������:1.�ж������Ƿ���� 2.���������,���뻷�ĵ�һ���ڵ�
//���뻷�ĵ�һ���ڵ�ķ�����,��fast��slow�ڻ���������,
//��fast��λ������ˢ�µ�head��,Ȼ��slow��fast��һ��һ����,ֱ������,
//�����ĵ�����뻷�ĵ�һ���ڵ�
//Ϊʲô�����ĵ�����뻷�ĵ�һ���ڵ�? fastҪ׷��slow����Ҫ����һȦ��
//����head���뻷���ľ���Ϊa,���ĳ���Ϊb,fast�ߵĻ���Ȧ��Ϊm(m>=1)
//��slow�ߵľ���һ��С��a+b,��a+x����ʾ,fast�ߵľ���Ϊa+x+mb
//����Ϊfast�ߵľ�����slow��2��,�����й�ʽ:a+x+mb=2(a+x),�����:a=mb-x

struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return NULL;
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
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
	//��ÿ���ڵ�ĺ��潫�Լ���next��val���Ƴ�һ���½ڵ�,�����ƽڵ��random
	while (cur != NULL)
	{
		Node* next = cur->next;
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->val = cur->val;
		newnode->next = next;
		cur->next = newnode;
		cur = next;
	}
	//�ٸ����Ƶ��½ڵ㸴��random
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
	//�����ƵĽڵ�������һ���һָ�ԭ����
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