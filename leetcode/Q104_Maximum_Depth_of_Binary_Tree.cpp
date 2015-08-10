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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int leftdep = maxDepth(root->left);
		int rightdep = maxDepth(root->right);
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
	a.left = &b;
	a.right = &c;
	b.left = &d;
	int res = so.maxDepth(&a);
	cout << res << endl;

	system("pause");
	return 0;
}
*/