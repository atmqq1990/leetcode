#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		TreeNode *last = root;
		if (root == NULL)
			return res;
		queue<TreeNode*> qu;
		qu.push(root);
		TreeNode *newlast = NULL;
		while (!qu.empty())
		{
			TreeNode *cur = qu.front();
			qu.pop();

			if (cur->left != NULL)
			{
				qu.push(cur->left);
				newlast = cur->left;
			}
			if (cur->right != NULL)
			{
				qu.push(cur->right);
				newlast = cur->right;
			}
			if (cur == last)
			{
				res.push_back(cur->val);
				last = newlast;
			}
		}
		return res;
	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(5);
	TreeNode e(4);
	a.left = &b;
	a.right = &c;
	b.right = &d;
	c.right = &e;
	vector<int> res = so.rightSideView(&a);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/