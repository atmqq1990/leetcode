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
	int sum;
	int sumNumbers(TreeNode* root) {
		if (root == NULL)
			return 0;
		sum = 0;
		subtreesum(root, 0);
		return sum;
	}

	void subtreesum(TreeNode *root, int presum)
	{
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
		{
			sum += presum * 10 + root->val;
			return;
		}
		if (root->left != NULL)
		{
			subtreesum(root->left, presum * 10 + root->val);
		}
		if (root->right != NULL)
		{
			subtreesum(root->right, presum * 10 + root->val);
		}
	}
};

/*
int main()
{
	Solution so;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;
	int res = so.sumNumbers(&a);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/