#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		if (k == 1)
		{
			TreeNode *cur = root;
			while (cur != NULL && cur->left != NULL)
				cur = cur->left;
			return cur->val;
		}

		int left_size = nodenumber(root->left);
		if (left_size == k - 1)
			return root->val;
		else if (left_size < k - 1)
			return kthSmallest(root->right, k - left_size - 1);
		else if (left_size == k)
		{
			TreeNode *cur = root->left;
			while (cur != NULL && cur->right != NULL)
				cur = cur->right;
			return cur->val;
		}
		else if (left_size > k)
		{
			return kthSmallest(root->left, k);
		}
	}


	int nodenumber(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		return nodenumber(root->left) + nodenumber(root->right) + 1;
	}
};