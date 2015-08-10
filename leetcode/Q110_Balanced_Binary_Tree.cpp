#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		int dep = depth(root);
		if (dep < 0)
			return false;
		return true;
	}

	int depth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int leftdep = depth(root->left);
		int rightdep = depth(root->right);
		if (leftdep < 0 || rightdep < 0)
			return -1;
		if (abs(leftdep - rightdep)>1)
			return -1;
		return max(leftdep,rightdep)+1;
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3); 
	TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	d.left = &f;
	bool res = so.isBalanced(&a);
	cout << res << endl;

	system("pause");
	return 0;
}
*/