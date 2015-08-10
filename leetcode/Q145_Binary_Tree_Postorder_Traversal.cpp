#include<iostream>
#include<stack>
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		stack<TreeNode*> st;
		stack<int> valuest;
		st.push(root);
		while (!st.empty())
		{
			TreeNode *cur = st.top();
			st.pop();
			valuest.push(cur->val);
			if (cur->left)
				st.push(cur->left);
			if (cur->right)
				st.push(cur->right);

		}

		while (!valuest.empty())
		{
			int v = valuest.top();
			valuest.pop();
			res.push_back(v);
		}

		return res;
	}
};

/*
int main()
{
	Solution so;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	vector<int> res = so.postorderTraversal(&a);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
*/