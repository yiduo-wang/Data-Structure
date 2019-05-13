//这些题目都已经在LeetCode上编译测试通过了, 所以只有运行的代码, 没有头文件以及测试用例

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

 //1.给定一个二叉树，返回它的 前序 遍历。
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

  //2.计算一个二叉树有多少个节点
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
	 * 动态创建二叉查找树
	 *
	 * @param treeRoot 根节点
	 * @param value    节点的值
	 */
  public static void createTree(TreeRoot treeRoot, int value) {

	  //如果树根为空(第一次访问)，将第一个值作为根节点
	  if (treeRoot.getTreeRoot() == null) {
		  TreeNode treeNode = new TreeNode(value);
		  treeRoot.setTreeRoot(treeNode);

	  }
	  else {

		  //当前树根
		  TreeNode tempRoot = treeRoot.getTreeRoot();

		  while (tempRoot != null) {
			  //当前值大于根值，往右边走
			  if (value > tempRoot.getValue()) {

				  //右边没有树根，那就直接插入
				  if (tempRoot.getRightNode() == null) {
					  tempRoot.setRightNode(new TreeNode(value));
					  return;
				  }
				  else {
					  //如果右边有树根，到右边的树根去
					  tempRoot = tempRoot.getRightNode();
				  }
			  }
			  else {
				  //左没有树根，那就直接插入
				  if (tempRoot.getLefTreeNode() == null) {
					  tempRoot.setLefTreeNode(new TreeNode(value));

					  return;
				  }
				  else {
					  //如果左有树根，到左边的树根去
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
	  if (!head) return 0; //如果树的根节点不存在，即树不存在，认为不是完全二叉树
	  struct node*p;
	  queue<struct node*>q;
	  while (!q.empty()) q.pop();
	  q.push(head);//根节点入队
	  while (p = q.front())//队首元素不为NULL代表该节点存在，拓展这个节点的儿子节点，若为NULL，说明搜索到的节点为空节点了，那么就遍历队列里已有元素
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
	  cout << "/节点的值：" << p->v << endl;
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
