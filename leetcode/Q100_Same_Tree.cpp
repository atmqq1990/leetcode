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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q != NULL)
			return false;
		if (p != NULL && q == NULL)
			return false;
		if (p == NULL && q == NULL)
			return true;
		if (p->val != q->val)
			return false;
		bool left = isSameTree(p->left, q->left);
		if (!left)
			return false;
		bool right = isSameTree(p->right, q->right);
		return right;
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

	TreeNode d(1);
	TreeNode e(2);
	TreeNode f(3);
	d.left = &e;
	d.right = &f;

	bool res =so.isSameTree(&a,&d);
	cout<<res<<endl;

	system("pause");
	return 0;
}
*/