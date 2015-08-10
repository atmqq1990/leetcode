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
	void flatten(TreeNode* root) {
		adjust(root);
	}

	TreeNode* adjust(TreeNode *root)
	{
		if (root == NULL)
			return NULL;
		if (root->left == NULL && root->right == NULL)
			return root;
		if (root->left != NULL && root->right == NULL)
		{
			root->right = root->left;
			root->left = NULL;
			return adjust(root->right);
		}
		else if (root->left == NULL && root->right != NULL)
		{
			return adjust(root->right);
		}
		else if (root->left != NULL && root->right != NULL)
		{
			TreeNode *orginalright = root->right;
			root->right = root->left;
			root->left = NULL;
			TreeNode *leftlast = adjust(root->right);
			leftlast->left = NULL;
			leftlast->right = orginalright;
			return adjust(orginalright);
		}
	}
};

void inorder_114(TreeNode *root)
{
	if (root)
	{
		inorder_114(root->left);
		cout << root->val << " ";
		inorder_114(root->right);
	}
}

/*
int main(int argc, char **args)
{
	Solution so;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	so.flatten(&a);
	inorder_114(&a);
	cout << endl;

	system("pause");
	return 0;
}
*/