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

 