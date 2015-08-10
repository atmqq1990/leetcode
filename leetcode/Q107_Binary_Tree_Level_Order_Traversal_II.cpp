#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		TreeNode *last = root;
		TreeNode *newlast = NULL;
		queue<TreeNode*> qu;
		stack<vector<int>> st;
		vector<int> vec;
		qu.push(root);

		while (!qu.empty())
		{
			TreeNode *temp = qu.front();
			qu.pop();
			vec.push_back(temp->val);
			if (temp->left)
				newlast = temp->left;
			if (temp->right)
				newlast = temp->right;
			if (temp == last)
			{
				st.push(vec);
				vec.clear();
				last = newlast;
			}
			if (temp->left)
				qu.push(temp->left);
			if (temp->right)
				qu.push(temp->right);
		}
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}
};

/*
int main()
{
	Solution so;
	TreeNode a(3);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;
	vector<vector<int>> res = so.levelOrderBottom(&a);
	for (int i = 0; i<res.size(); i++)
	{
		for (int j = 0; j<res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0; 
}
*/