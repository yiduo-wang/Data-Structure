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

 