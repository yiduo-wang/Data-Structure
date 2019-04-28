//这些题目都已经在LeetCode上编译测试通过了, 所以只有运行的代码, 没有头文件以及测试用例

struct ListNode {
	int val;
	struct ListNode *next;
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