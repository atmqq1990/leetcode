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
	bool isValidBST(TreeNode* root) {
		long long leftrange = INT_MIN;
		leftrange--;
		long long rightrange = INT_MAX;
		rightrange++;
		return valid(root, leftrange, rightrange);
	}

	bool valid(TreeNode *root, long long leftrange, long long rightrange)
	{
		if (root == NULL)
			return true;
		if (root->val <= leftrange || root->val >= rightrange)
			return false;

		bool left = valid(root->left, leftrange, root->val);
		bool right = valid(root->right, root->val, rightrange);

		return left&&right;
	}
};

/*
int main()
{
	Solution so;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right = &b;
	b.left = &c;
	bool res = so.isValidBST(&a);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/