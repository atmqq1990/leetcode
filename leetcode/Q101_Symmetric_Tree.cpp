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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		if (root->left != NULL && root->right == NULL)
			return false;
		if (root->left == NULL && root->right != NULL)
			return false;
		if (root->left == NULL && root->right == NULL)
			return true;
		return isSys(root->left, root->right);
	}

	bool isSys(TreeNode *p, TreeNode *q)
	{
		if (p == NULL && q != NULL)
			return false;
		if (p != NULL && q == NULL)
			return false;
		if (p == NULL && q == NULL)
			return true;
		if (p->val != q->val)
			return false;
		bool left = isSys(p->left, q->right);
		if (!left)
			return false;
		bool right = isSys(p->right, q->left);
		return right;
	}

};

/*
int main()
{
	Solution so;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(2);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(4);
	TreeNode g(3);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;
	bool res = so.isSymmetric(&a);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/