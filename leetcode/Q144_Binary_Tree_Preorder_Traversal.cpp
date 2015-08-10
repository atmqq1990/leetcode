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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if (root == NULL)
			return res;
		st.push(root);

		while (!st.empty())
		{
			TreeNode *cur = st.top();
			st.pop();
			res.push_back(cur->val);
			if (cur->right != NULL)
				st.push(cur->right);
			if (cur->left != NULL)
				st.push(cur->left);
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
	TreeNode d(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	vector<int> res = so.preorderTraversal(&a);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/