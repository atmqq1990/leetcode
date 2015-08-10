#include<iostream>
#include<vector>
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		TreeNode *current = root;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			while (current->left != NULL)
			{
				st.push(current->left);
				current = current->left;
			}

			if (!st.empty())
			{
				TreeNode * temp = st.top();
				st.pop();
				res.push_back(temp->val);
				if (temp->right != NULL)
				{
					st.push(temp->right);
					current = temp->right;
				}
			}
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
	a.right = &b;
	b.left = &c;
	vector<int> res = so.inorderTraversal(&a);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
*/