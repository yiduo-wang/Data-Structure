//��Щ��Ŀ���Ѿ���LeetCode�ϱ������ͨ����, ����ֻ�����еĴ���, û��ͷ�ļ��Լ���������

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

 //1.����һ������������������ ǰ�� ������
  void perorder(struct TreeNode* root, int* returnSize, int* arr)
  {
	  if (root != NULL)
	  {
		  arr[*returnSize] = root->val;
		  (*returnSize)++;
		  perorder(root->left, returnSize, arr);
		  perorder(root->right, returnSize, arr);
	  }
  }

  int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	  int* arr = (int*)malloc(sizeof(int) * 1000);
	  *returnSize = 0;
	  perorder(root, returnSize, arr);
	  return arr;
  }

  //2.����һ���������ж��ٸ��ڵ�
  void levelOrderTraversal(vector<int> &store, TreeNode *root) {
	  queue<TreeNode *> Q;
	  Q.push(root);
	  while (!Q.empty()) {
		  TreeNode *curr_node = Q.front();
		  if (curr_node) {
			  store.push(curr_node->val);
			  Q.push(curr_node->left);
			  Q.push(curr_node->right);
		  }
	  }
	  return;
  }



  /**
	 * ��̬�������������
	 *
	 * @param treeRoot ���ڵ�
	 * @param value    �ڵ��ֵ
	 */
  public static void createTree(TreeRoot treeRoot, int value) {

	  //�������Ϊ��(��һ�η���)������һ��ֵ��Ϊ���ڵ�
	  if (treeRoot.getTreeRoot() == null) {
		  TreeNode treeNode = new TreeNode(value);
		  treeRoot.setTreeRoot(treeNode);

	  }
	  else {

		  //��ǰ����
		  TreeNode tempRoot = treeRoot.getTreeRoot();

		  while (tempRoot != null) {
			  //��ǰֵ���ڸ�ֵ�����ұ���
			  if (value > tempRoot.getValue()) {

				  //�ұ�û���������Ǿ�ֱ�Ӳ���
				  if (tempRoot.getRightNode() == null) {
					  tempRoot.setRightNode(new TreeNode(value));
					  return;
				  }
				  else {
					  //����ұ������������ұߵ�����ȥ
					  tempRoot = tempRoot.getRightNode();
				  }
			  }
			  else {
				  //��û���������Ǿ�ֱ�Ӳ���
				  if (tempRoot.getLefTreeNode() == null) {
					  tempRoot.setLefTreeNode(new TreeNode(value));

					  return;
				  }
				  else {
					  //�����������������ߵ�����ȥ
					  tempRoot = tempRoot.getLefTreeNode();
				  }
			  }
		  }
	  }
  }

#include<stdio.h>
#include<iostream>
#include<queue>
#include<stdlib.h>
  using namespace std;
  struct node
  {
	  char v;
	  int num;
	  int depth;
	  struct node*ls, *rs;
  };


  struct node*head;
  struct node*build()
  {
	  char ch;
	  cin >> ch;
	  if (ch == '#') return NULL;
	  struct node*p = (struct node*)malloc(sizeof(struct node));
	  p->v = ch;
	  p->ls = build();
	  p->rs = build();
	  return p;

  };


  int judge()
  {
	  if (!head) return 0; //������ĸ��ڵ㲻���ڣ����������ڣ���Ϊ������ȫ������
	  struct node*p;
	  queue<struct node*>q;
	  while (!q.empty()) q.pop();
	  q.push(head);//���ڵ����
	  while (p = q.front())//����Ԫ�ز�ΪNULL����ýڵ���ڣ���չ����ڵ�Ķ��ӽڵ㣬��ΪNULL��˵���������Ľڵ�Ϊ�սڵ��ˣ���ô�ͱ�������������Ԫ��
	  {
		  q.push(p->ls);
		  q.push(p->rs);
		  q.pop();
	  }
	  while (!q.empty())
	  {
		  if (q.front()) return 0;
		  q.pop();

	  }
	  return 1;

  }
  void first(struct node *p)
  {
	  if (!p) return;
	  cout << "/�ڵ��ֵ��" << p->v << endl;
	  first(p->ls);
	  first(p->rs);
  }

  int main()
  {



	  head = build();

	  if (judge())
		  cout << "yes" << endl;
	  else
		  cout << "no" << endl;

	  return 0;
  }
