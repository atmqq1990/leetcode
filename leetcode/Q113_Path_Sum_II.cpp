#include<iostream>
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
	vector<vector<int>> res;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> pre;
		path(root,pre,0,sum);
		return res;
	}

	void path(TreeNode *root, vector<int> pre, int presum, int sum)
	{
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
		{
			if (presum + root->val == sum)
			{
				pre.push_back(root->val);
				res.push_back(pre);
				return;
			}
		}
		else
		{
			pre.push_back(root->val);
			if (root->left != NULL)
				path(root->left, pre, presum + root->val, sum);
			if (root->right != NULL)
				path(root->right, pre, presum + root->val, sum);
		}
	}
};

/*
int main(int argc, char **args)
{
	Solution so;
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode i(5);
	TreeNode j(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.left = &i;
	f.right = &j;
	vector<vector<int>> res = so.pathSum(&a,22);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
*/