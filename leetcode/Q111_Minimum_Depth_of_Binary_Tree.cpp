#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int leftdep = minDepth(root->left);
		int rightdep = minDepth(root->right);
		if (leftdep > 0 && rightdep > 0)
			return min(leftdep, rightdep) + 1;
		else
			return max(leftdep, rightdep) + 1;
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
	int res = so.minDepth(&a);
	cout << res << endl;

	system("pause");
	return 0;
}
*/