#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		queue<TreeNode*> qu;
		TreeNode *last = root;
		vector<int> vec;
		qu.push(root);
		TreeNode *newlast = NULL;
		int flag = 1;
		stack<int> st;
		while (!qu.empty())
		{
			TreeNode *cur = qu.front();
			qu.pop();
			if (flag == 1)
				vec.push_back(cur->val);
			else
				st.push(cur->val);

			if (cur->left)
				newlast = cur->left;
			if (cur->right)
				newlast = cur->right;

			if (cur == last)
			{									
				while (!st.empty())
				{
					vec.push_back(st.top());
					st.pop();
				}
				res.push_back(vec);
				vec.clear();		
				last = newlast;
				flag = 1 - flag;
			}

			if (cur->left)
				qu.push(cur->left);
			if (cur->right)
				qu.push(cur->right);
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
	vector<vector<int>> res =so.zigzagLevelOrder(&a);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		cout<<res[i][j]<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}
*/