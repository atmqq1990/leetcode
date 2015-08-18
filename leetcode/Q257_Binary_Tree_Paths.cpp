#include<iostream>
#include<string>
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
	vector<string> res;
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL)
			return res;
		vector<int> pre;
		addpath(root,pre);
		return res;
	}

	void addpath(TreeNode *root, vector<int>& pre)
	{
		pre.push_back(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			string temp;
			for (int i = 0; i < pre.size(); i++)
			{
				temp.append(to_string(pre[i]));
				temp.push_back('-');
				temp.push_back('>');
			}
			temp.pop_back();
			temp.pop_back();
			res.push_back(temp);
		}
		if (root->left != NULL)
			addpath(root->left,pre);
		if (root->right != NULL)
			addpath(root->right,pre);
		pre.pop_back();
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
	a.left = &b;
	a.right = &c;
	b.right = &d;
	vector<string> res = so.binaryTreePaths(&a);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

	system("pause");
	return 0;
}
*/