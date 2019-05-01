//这些题目都已经在LeetCode上编译测试通过了, 所以只有运行的代码, 没有头文件以及测试用例

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

//1.判断链表是否回文(找中间节点的时候找第一个)
//本题在找中间节点的时候和本身找中间节点题目有所不同
//前者如果有两个节点找第一个,后者如果有两个节点找第二个
//逆置链表
struct ListNode* reverse(struct ListNode* head)
{
	//空链表或者只有一个节点
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
		//空链表或者只有一个节点
		if (A == NULL || A->next == NULL)
			return true;
		//至少有两个节点
		//找中间节点(两个中间节点则找第一个)
		struct ListNode* fast = A;
		struct ListNode* slow = A;
		while (fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//逆置链表
		fast = reverse(slow->next);
		//中间节点以后置为空
		slow->next = NULL;
		//1->2->3->4
		//fast:4->3->NULL    slow:1->2->NULL       中间节点:2
		//1->2->3->4->5
		//fast:5->4->NULL    slow:1->2->3->NULL    中间节点:3
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

//2.编写一个程序，找到两个单链表相交的起始节点。
//本题主要问题是要让两个链表的起始位置到结束位置的距离相同
int Length(struct ListNode* head)
{
	//计算链表长度
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

//3.给定一个链表，判断链表中是否有环。
//要保证fast走的距离是slow走的距离的2倍
//为了防止fast和slow在head的位置相等,而head是一个单链表,
//所以在循环的时候,要让slow和fast先走,然后再判断fast是否和slow相等
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

//4.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//两个步骤:1.判断链表是否带环 2.如果带环了,找入环的第一个节点
//找入环的第一个节点的方法是,当fast和slow在环内相遇后,
//将fast的位置立即刷新到head处,然后slow和fast都一步一步走,直到相遇,
//相遇的点就是入环的第一个节点
//为什么相遇的点就是入环的第一个节点? fast要追上slow至少要走上一圈环
//假设head到入环处的距离为a,环的长度为b,fast走的环的圈数为m(m>=1)
//则slow走的距离一定小于a+b,用a+x来表示,fast走的距离为a+x+mb
//又因为fast走的距离是slow的2倍,所以有公式:a+x+mb=2(a+x),化简得:a=mb-x

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

//复杂链表的复制
Node* copyRandomList(Node* head) {
	if (head == NULL)
		return NULL;
	Node* cur = head;
	//在每个节点的后面将自己的next和val复制成一个新节点,不复制节点的random
	while (cur != NULL)
	{
		Node* next = cur->next;
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->val = cur->val;
		newnode->next = next;
		cur->next = newnode;
		cur = next;
	}
	//再给复制的新节点复制random
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
	//将复制的节点连接在一起并且恢复原链表
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