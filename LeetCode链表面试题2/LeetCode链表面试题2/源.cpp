//��Щ��Ŀ���Ѿ���LeetCode�ϱ������ͨ����, ����ֻ�����еĴ���, û��ͷ�ļ��Լ���������

struct ListNode {
	int val;
	struct ListNode *next;
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